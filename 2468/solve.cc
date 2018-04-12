#include <iostream>
#include <cstring>

using namespace std;

int n;
int height[101][101];
bool visited[101][101];

const int offset[4][2] = {
  0, 1, 0, -1, 1, 0, -1, 0
};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, int h) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + offset[i][0];
    int ny = y + offset[i][1];

    if (valid(nx, ny) && !visited[nx][ny] && height[nx][ny] > h)
      dfs(nx, ny, h);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> height[i][j];
    }
  }

  int m = 0;
  for (int k = 0; k < 101; k++) {
    memset(visited, 0, sizeof(visited));
    int result = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && height[i][j] > k) {
          dfs(i, j, k);
          result++;
        }
      }
    }

    m = max(m, result);
  }

  cout << m << "\n";
}
