#include <iostream>
#include <queue>

using namespace std;


const int offset[4][2] = {
  1, 0, -1, 0, 0, 1, 0, -1
};

int n, m;

int main() {
  char map[1001][1001];
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  bool visited[1001][1001][2] = {};
  queue<pair<int, bool>> q;
  q.push(make_pair(0, false));
  visited[0][0][false] = true;

  int step = 1;

  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      pair<int, bool> p = q.front();
      q.pop();

      int x = p.first / 1000;
      int y = p.first % 1000;

      // printf("%d: %d, %d, %d\n", step, x, y, p.second);

      if (x == n - 1 && y == m - 1) {
        printf("%d\n", step);
        return 0;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + offset[i][0];
        int ny = y + offset[i][1];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (map[nx][ny] == '0' && !visited[nx][ny][p.second]) {
            q.push(make_pair(nx * 1000 + ny, p.second));
            visited[nx][ny][p.second] = true;
          }
          else if (map[nx][ny] == '1'
              && !p.second
              && !visited[nx][ny][true]) {
            q.push(make_pair(nx * 1000 + ny, true));
            visited[nx][ny][true] = true;
          }
        }
      }
    }

    step++;
  }

  printf("-1\n");
}
