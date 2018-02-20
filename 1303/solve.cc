#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> vert;
vector<vector<int>> adj;
vector<bool> visited;

int node_num(int i, int j) {
  return i * n + j;
}

int dfs(int x, int y) {
  int num = node_num(x, y);
  if (visited[num])
    return 0;
  int sum = 1;
  visited[num] = true;
  for (int there : adj[num]) {
      sum += dfs(there / n, there % n);
  }

  return sum;
}

int main() {
  std::string line;
  cin >> n >> m;
  getline(cin, line); // Remove line feed

  vert.resize(m);
  for (int i = 0; i < m; i++) {
    getline(cin, line);
    // cout << line << "\n";
    assert(line.size() == n);
    for (int j = 0; j < n; j++)
      vert[i].push_back(line[j]);
  }

  adj.resize(n * m);
  visited.resize(n * m);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i != m - 1 && vert[i][j] == vert[i + 1][j]) {
//        printf("! %d(%c)->%d(%c)\n", node_num(i, j), vert[i][j],
//            node_num(i + 1, j), vert[i + 1][j]);
        adj[node_num(i, j)].push_back(node_num(i + 1, j));
        adj[node_num(i + 1, j)].push_back(node_num(i, j));
      }
      if (j != n - 1 && vert[i][j] == vert[i][j + 1]) {
//        printf("!! %d(%c)->%d(%c)\n", node_num(i, j), vert[i][j],
//            node_num(i, j + 1), vert[i][j + 1]);
        adj[node_num(i, j)].push_back(node_num(i, j + 1));
        adj[node_num(i, j + 1)].push_back(node_num(i, j));
      }
    }
  }
#if 0
  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < n * m; j++) {
      if (adj[i][j])
        printf("%d -> %d\n", i, j);
    }
  }
  printf("\n");
#endif
  int wsum = 0, bsum = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int value = dfs(i, j);
      if (vert[i][j] == 'W')
        wsum += value * value;
      else
        bsum += value * value;
    }
  }

  cout << wsum << " " << bsum << "\n";
}
