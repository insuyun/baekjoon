#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n, k;

bool mark[101][101];
bool visited[101][101];

int offset[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
vector<int> v_area;
int area = 0;

void dfs(int x, int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + offset[i][0];
    int ny = y + offset[i][1];

    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
        !mark[nx][ny] && !visited[nx][ny])
      dfs(nx, ny);
  }

  area++;
}

int main() {
  cin >> n >> m >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // cout << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << "\n";

    for (int i = x1; i < x2; i++) {
      for (int j = y1; j < y2; j++) {
        mark[i][j] = true;
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && !mark[i][j]) {
        area = 0;
        dfs(i, j);
        v_area.push_back(area);
      }
    }
  }

  cout << v_area.size() << "\n";
  sort(v_area.begin(), v_area.end());
  for (auto a : v_area)
    cout << a << " ";
  cout << "\n";

#if 0
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < m; i++) {
//      cout << "\ni: " << i << ", j: " << j << ": " << mark[i][j] << "\n";

      if (mark[i][j])
        cout << "1";
      else
        cout << "0";
    }

    cout << "\n";
  }
#endif
}
