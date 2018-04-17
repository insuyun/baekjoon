#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int offset[4][2] = {
  1, 0, -1, 0, 0, 1, 0, -1
};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    char map[1001][1001];
    int sx, sy;
    cin >> m >> n;

    queue<pair<int, int>> q2;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> map[i][j];
//        fprintf(stderr, "map[%d][%d]: %c\n", i, j, map[i][j]);
        if (map[i][j] == '@') {
          sx = i;
          sy = j;
          map[i][j] = '.';
        }
        else if (map[i][j] == '*') {
          q2.push(make_pair(i, j));
        }
      }
    }

    bool visited[1001][1001] = {};
    queue<pair<int, int>> q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    int result = 1;

    while (!q.empty()) {
      int qsize = q.size();

      // update map
      int q2size = q2.size();
      while (q2size--) {
        pair<int, int> p = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++) {
          int nx = p.first + offset[i][0];
          int ny = p.second + offset[i][1];
          if (valid(nx, ny) && map[nx][ny] == '.') {
            q2.push(make_pair(nx, ny));
            map[nx][ny] = '*';
          }
        }
      }

      while (qsize--) {
        pair<int, int> p = q.front();
        q.pop();
        //fprintf(stderr, "%d, %d\n", p.first, p.second);

        if (p.first == n - 1
            || p.first == 0
            || p.second == m - 1
            || p.second == 0) {
          printf("%d\n", result);
          goto out;
        }

        for (int i = 0; i < 4; i++) {
          int nx = p.first + offset[i][0];
          int ny = p.second + offset[i][1];
          //fprintf(stderr, "next: %d, %d: %c\n", nx, ny, map[nx][ny]);
          if (valid(nx, ny) && !visited[nx][ny] && map[nx][ny] == '.') {
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
          }
        }
      }

      result++;
    }
    printf("IMPOSSIBLE\n");
out:
    continue;
  }
}
