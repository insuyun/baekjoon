#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>

using namespace std;

const int kMax = 52 * 52 * 2;
const int INF = 10000000;
const int kMaxCol = 51;
const int kEnd = kMax - 1;
const int kStart = 0;
vector<int> edges[kMax];
int c[kMax][kMax];
int f[kMax][kMax];

int n, m;

void add_edge(int x, int y, int w) {
  // cout << "add_edge: " << x << "->" << y << " (" << w << ")\n";
  edges[x].push_back(y);
  edges[y].push_back(x);
  assert(c[x][y] == 0);
  c[x][y] = w;
}

int node_id(int x, int y) {
  return x * kMaxCol + y;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int sum = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int w;
        cin >> w;
        sum += w;
        if ((i + j) % 2 == 0)
          add_edge(kStart, node_id(i, j), w);
        else
          add_edge(node_id(i, j), kEnd, w);
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if ((i + j) % 2 == 0) {
          if (i != n)
            add_edge(node_id(i, j), node_id(i + 1, j), INF);
          if (i != 1)
            add_edge(node_id(i, j), node_id(i - 1, j), INF);
          if (j != m)
            add_edge(node_id(i, j), node_id(i, j + 1), INF);
          if (j != 1)
            add_edge(node_id(i, j), node_id(i, j - 1), INF);
        }
      }
    }

    int max_flow = 0;
    while (true) {
      bool visited[kMax] = {};
      int parent[kMax] = {};
      visited[kStart] = true;
      queue<int> q;
      q.push(kStart);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : edges[u]) {
          if (!visited[v] && c[u][v] - f[u][v] > 0) {
            visited[v] = true;
            q.push(v);
            parent[v] = u;
          }
        }
      }

      if (!visited[kEnd])
        break;

      int u = kEnd;
      int flow = INF;
      while (u != kStart) {
        flow = min(flow, c[parent[u]][u] - f[parent[u]][u]);
        u = parent[u];
      }

      u = kEnd;
      while (u != kStart) {
        f[parent[u]][u] += flow;
        f[u][parent[u]] -= flow;
        u = parent[u];
      }

      // cout << "flow: " << flow << "\n";
      max_flow += flow;
    }

    // cout << "max_flow: " << max_flow << "\n";
    cout << max_flow + (sum - 2 * max_flow) << "\n";

    // Cleanup
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        edges[node_id(i, j)].clear();
      }
    }

    edges[kStart].clear();
    edges[kEnd].clear();

    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
  }
}
