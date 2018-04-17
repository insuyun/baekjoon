#include <iostream>
#include <queue>

using namespace std;

char cell[101][101];
const int offset[4][2] = {
  1, 0,
  -1, 0,
  0, 1,
  0, -1
};

int n, m;

bool valid(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
  queue<pair<int, int>> q;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> cell[i][j];
      cell[i][j] -= '0';
//      fprintf(stderr, "%d, %d: %d\n", i, j, cell[i][j]);
    }
  }

  bool visited[101][101] = {};
  q.push(make_pair(1, 1));
  visited[1][1] = true;
  int result = 0;
  bool found = false;

  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      pair<int, int> p = q.front();
      if (p.first == n && p.second == m) {
        found = true;
        break;
      }
      // fprintf(stderr, "%d, %d\n", p.first, p.second);
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = p.first + offset[i][0];
        int ny = p.second + offset[i][1];

        if (valid(nx, ny) && !visited[nx][ny] && cell[nx][ny]) {
          visited[nx][ny] = true;
          q.push(make_pair(nx, ny));
        }
      }
    }

    if (found)
      break;
    result++;
  }

  result++;
  cout << result << "\n";
}
