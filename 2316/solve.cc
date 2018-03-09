#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, p;
const int kDual = 401;
const int kMax = kDual * 2;
const int kStart = 1;
const int INF = 10000000;

int dual(int x) {
  return x + kDual;
}

const int kEnd = dual(2);
vector<int> edges[kMax];
int c[kMax][kMax];
int f[kMax][kMax];
int parent[kMax];
bool visited[kMax];

int main() {
  cin >> n >> p;

  // Connect vectex with its dual vertex
  for (int i = 1; i <= n; i++) {
    edges[i].push_back(dual(i));
    edges[dual(i)].push_back(i);
    c[i][dual(i)] = i < 3 ? INF : 1;
  }

  while (p--) {
    int a, b;
    cin >> a >> b;
    edges[dual(a)].push_back(b);
    edges[b].push_back(dual(a));
    edges[dual(b)].push_back(a);
    edges[a].push_back(dual(b));
    c[dual(a)][b] = 1;
    c[dual(b)][a] = 1;
  }

  int total = 0;
  while (true) {
    queue<int> q;
    q.push(kStart);
    visited[kStart] = true;
    memset(visited, 0, sizeof(visited));

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : edges[u]) {
        if (!visited[v] && c[u][v] - f[u][v] > 0) {
          // cout << "u->v: " << u << "-> " << v << "\n";
          visited[v] = true;
          q.push(v);
          parent[v] = u;
        }
      }
    }

    // Cannot find a path
    if (!visited[kEnd])
      break;

    int flow = INF;
    int u = kEnd;
    while (u != kStart) {
      // cout << "u: " << u << "\n";
      flow = min(flow, c[parent[u]][u] - f[parent[u]][u]);
      u = parent[u];
    }

    u = kEnd;
    while (u != kStart) {
      f[parent[u]][u] += flow;
      f[u][parent[u]] -= flow;
      u = parent[u];
    }

    total += flow;
  }

  cout << total << "\n";

}
