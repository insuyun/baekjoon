#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxNum = 201 * 2 + 2;
const int kStart = 201;
const int kSource = kMaxNum - 1;
const int kDest = kMaxNum - 2;
const int INF = 100000000;

int n, m;
int c[kMaxNum][kMaxNum];
int f[kMaxNum][kMaxNum];

bool visited[kMaxNum];
int parent[kMaxNum];

vector<int> edges[kMaxNum];

int to_house(int x) {
  return x + kStart;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    while (s--) {
      int a;
      cin >> a;
      a = to_house(a);

      edges[i].push_back(a);
      edges[a].push_back(i);
      c[i][a] = 1;
      edges[kSource].push_back(i);
      edges[i].push_back(kSource);
      c[kSource][i] = 1;

      edges[kDest].push_back(a);
      edges[a].push_back(kDest);
      c[a][kDest] = 1;
    }
  }

  int total = 0;
  while (true) {
    queue<int> q;
    q.push(kSource);
    visited[kSource] = true;
    memset(visited, 0, sizeof(visited));

    while (!q.empty()) {
      int u = q.front();
      // cout << "u: " << u << "\n";
      q.pop();

      for (int v : edges[u]) {
        if (!visited[v] && c[u][v] - f[u][v] > 0) {
          visited[v] = true;
          q.push(v);
          parent[v] = u;
        }
      }
    }

    // Cannot find a path
    if (!visited[kDest])
      break;

    // If we find a path
    int flow = INF;
    int u = kDest;

    while (u != kSource) {
      flow = min(c[parent[u]][u], flow);
      u = parent[u];
    }

    u = kDest;
    while (u != kSource) {
      c[parent[u]][u] -= flow;
      c[u][parent[u]] += flow;
      u = parent[u];
    }

    total += flow;
  }

  cout << total << "\n";
}
