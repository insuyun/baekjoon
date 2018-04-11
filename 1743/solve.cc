#include <iostream>
#include <vector>

using namespace std;

bool visited[101][101];
bool trashes[101][101];
vector<pair<int, int>> edges[101][101];
int c, n, m, k;

void dfs(int x, int y) {
  if (!trashes[x][y]
      || x == 0 || y == 0 || x > n || y > m
      || visited[x][y])
    return;

  c++;
  visited[x][y] = true;
  dfs(x - 1, y);
  dfs(x, y - 1);
  dfs(x + 1, y);
  dfs(x, y + 1);
}

int main() {
  cin >> n >> m >> k;

  while (k--) {
    int x, y;
    cin >> x >> y;
    trashes[x][y] = true;
  }

  int r = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!visited[i][j]) {
        c = 0;
        dfs(i, j);
        r = max(r, c);
      }
    }
  }
  cout << r << "\n";
}
