#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMax = 10000 + 1;
int n, m;
vector<pair<int, int>> edges[kMax];
vector<pair<int, int>> edges_r[kMax];
int indegree[kMax];
int parent[kMax];
int weight[kMax];

int main() {
  cin >> n >> m;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    edges[x].push_back(make_pair(y, w));
    edges_r[y].push_back(make_pair(x, w));
    indegree[y]++;
  }

  int s, e;
  cin >> s >> e;

  queue<int> q;

  for (int i = 1; i <= n ; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  bool start = false;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == s)
      start = true;

    for (pair<int, int>& p : edges[u]) {
      int v = p.first;
      int w = p.second;

      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);

      if (start)
        weight[v] = max(weight[u] + w, weight[v]);
    }
  }

  cout << weight[e] << "\n";

  bool visited[n + 1] = {};
  // 1. go backward to find reachable node from e
  q = queue<int>();
  q.push(e);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;

    for (pair<int, int>&p : edges_r[u]) {
      int v = p.first;
      int w = p.second;

      if (!visited[v] && weight[v] == weight[u] - w) {
        q.push(v);
//        cout << "v: " << v << "\n";
        visited[v] = true;
      }
    }
  }

  // 2. go forward to find recheable node from s using e
  bool visited2[n + 1] = {};
  q = queue<int>();
  q.push(s);

  int nedge = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited2[u] = true;

    for (pair<int, int>&p : edges[u]) {
      int v = p.first;
      int w = p.second;

      if (weight[v] == weight[u] + w) {
        if (visited[v]) {
//          cout << "u:" << u << " -> v: " << v << "\n";
          nedge++;
          if (!visited2[v]) {
            q.push(v);
            visited2[v] = true;
          }
        }
      }
    }
  }

  cout << nedge << "\n";
}
