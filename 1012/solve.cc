#include <iostream>
#include <cstring>

using namespace std;

int m, n, k;

bool cell[51][51];
bool visited[51][51];

void dfs(int x, int y) {
  if (visited[x][y])
    return;

  visited[x][y] = true;

  if (x < m - 1 && cell[x + 1][y])
    dfs(x + 1, y);

  if (x > 0 && cell[x - 1][y])
    dfs(x - 1, y);

  if (y < n - 1 && cell[x][y + 1])
    dfs(x, y + 1);

  if (y > 0 && cell[x][y - 1])
    dfs(x, y - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(cell, 0, sizeof(cell));
    memset(visited, 0, sizeof(visited));
    cin >> m >> n >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      cell[x][y] = true;
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (cell[i][j] && !visited[i][j]) {
          dfs(i, j);
          count++;
        }
      }
    }

    cout << count << "\n";
  }
}
