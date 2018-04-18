#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;

vector<int> edges[MAX];
bool visited[MAX];

void dfs(int u) {
  visited[u] = true;

  for (int v : edges[u]) {
    if (!visited[v]) dfs(v);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int ncc = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ncc++;
      dfs(i);
    }
  }
  cout << ncc << "\n";
}
