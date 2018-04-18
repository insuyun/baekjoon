#include <iostream>
#include <queue>

using namespace std;

const int offset[8][2] = {
  -2, 1,
  -2, -1,
  -1, 2,
  -1, -2,
   1, 2,
   1, -2,
   2, 1,
   2, -1
};

int n;

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int run() {
    cin >> n;
    int sx, sy, ex, ey;
    queue<int> q;
    bool visited[300][300] = {};

    cin >> sx >> sy >> ex >> ey;
    q.push(sx * 300 + sy);
    visited[sx][sy] = true;

    int step = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int x = q.front() / 300;
        int y = q.front() % 300;
        q.pop();

        if (x == ex && y == ey)
          return step;

        for (int i = 0; i < 8; i++) {
          int nx = x + offset[i][0];
          int ny = y + offset[i][1];

          if (valid(nx, ny) && !visited[nx][ny]) {
            q.push(nx * 300 + ny);
            visited[nx][ny] = true;
          }
        }
      }

      step++;
    }

    return -1;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    printf("%d\n", run());
  }
}
