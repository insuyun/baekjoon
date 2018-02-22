#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
const int kMaxVerticies = 1001;

vector<int> edges[kMaxVerticies];
bool visited[kMaxVerticies];

void dfs(int v) {
  if (visited[v])
    return;

  cout << v << " ";
  visited[v] = true;

  for (int dst : edges[v])
    dfs(dst);
}

void bfs() {
  queue<int> q;
  q.push(v);
  visited[v] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    cout << v << " ";

    for (int dst : edges[v]) {
      if (!visited[dst]) {
        q.push(dst);
        visited[dst] = true;
      }
    }
  }
}

int main() {
  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 0; i <= n; i++)
    sort(edges[i].begin(), edges[i].end());

  memset(visited, 0, sizeof(visited));
  dfs(v);
  cout << "\n";

  memset(visited, 0, sizeof(visited));
  bfs();
  cout << "\n";
}
