#include <iostream>
#include <queue>

using namespace std;

int n, m;
int box[1000][1000];

const int offset[4][2] = {
  1, 0, -1, 0, 0, 1, 0, -1
};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  cin >> m >> n;
  queue<int> q;
  int num = 0;
  bool visited[1000][1000] = {};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];
      if (box[i][j] == 1) {
        visited[i][j] = true;
        q.push(i * 1000 + j);
      }
      else if (box[i][j] == -1) {
        visited[i][j] = true;
        num++;
      }
    }
  }

  int step = 0;

  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      int x = q.front() / 1000;
      int y = q.front() % 1000;
      q.pop();
      num++;

//      printf("%d, %d\n", x, y);

      if (num == n * m) {
        printf("%d\n", step);
        return 0;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + offset[i][0];
        int ny = y + offset[i][1];

        if (valid(nx, ny) && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push(nx * 1000 + ny);
        }
      }
    }
    step++;
  }

  printf("-1\n");
}
