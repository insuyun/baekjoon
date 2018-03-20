#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int kMax = 10301;
const int kStart = 1;
const int INF = 10000000;

int n, m;
int nid;

vector<int> edges[kMax];
int c[kMax][kMax];
int f[kMax][kMax];

void add_edge(int x, int y, int w) {
  edges[x].push_back(y);
  edges[y].push_back(x);
  c[x][y] = w;
}

int main() {
  int k;
  cin >> k;
  while (k--) {
    cin >> n >> m;
    nid = n + 1;

    while (m--) {
      int f, t, b;
      cin >> f >> t >> b;
      if (c[f][t] != 0) {
        // already have edge
        add_edge(f, nid, b);
        add_edge(nid, t, b);
        nid++;
      }
      else
        add_edge(f, t, b);
    }

    while (true) {
      bool visited[kMax] = {};
      int parent[kMax] = {};
      queue<int> q;

      q.push(kStart);
      visited[kStart] = true;

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

      if (!visited[n])
        break;

      int u = n;
      int flow = INF;
      while (u != kStart) {
        flow = min(flow, c[parent[u]][u] - f[parent[u]][u]);
        u = parent[u];
      }

      u = n;
      while (u != kStart) {
        f[parent[u]][u] += flow;
        f[u][parent[u]] -= flow;
        u = parent[u];
      }

      // cout << flow << "\n";
    }

    int n_critical = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < nid; j++) {
        if (i == j) continue; // no self loop
        if (c[i][j] - f[i][j] == 0 && c[i][j] != 0) {
          bool visited[kMax] = {};
          queue<int> q;
          q.push(i);
          visited[i] = true;

          while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : edges[u]) {
              if (!visited[v] && c[u][v] - f[u][v] > 0) {
                visited[v] = true;
                q.push(v);
              }
            }
          }

          if (!visited[j])
            n_critical++;
        }
      }
    }

    cout << n_critical << "\n";
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));

    for (int i = 1; i < nid; i++)
      edges[i].clear();
  }
}
