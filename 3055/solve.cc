#include <iostream>
#include <queue>

using namespace std;

const int offset[4][2] = {
  0, 1, 0, -1, 1, 0, -1, 0
};

int r, c;

bool valid(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
  int sx, sy;
  char map[51][51];

  cin >> r >> c;

  queue<int> q1, q2;
  bool visited[51][51] = {};

  for (int i = 0 ; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'S') {
        q1.push(i * 51 + j);
        visited[i][j] = true;
      }
      else if (map[i][j] == '*')
        q2.push(i * 51 + j);
    }
  }

  int step = 0;

  while (!q1.empty()) {
    // update map
    int q2size = q2.size();
    while (q2size--) {
      int x = q2.front() / 51;
      int y = q2.front() % 51;
//      printf("FILL: %d, %d\n", x, y);
      q2.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + offset[i][0];
        int ny = y + offset[i][1];
        if (valid(nx, ny) && map[nx][ny] == '.') {
          map[nx][ny] = '*';
          q2.push(nx * 51 + ny);
        }
      }
    }

    int q1size = q1.size();
    while (q1size--) {
      int x = q1.front() / 51;
      int y = q1.front() % 51;
      q1.pop();

      if (map[x][y] == 'D') {
        printf("%d\n", step);
        return 0;
      }

//      printf("MOVE: %d, %d\n", x, y);

      for (int i = 0; i < 4; i++) {
        int nx = x + offset[i][0];
        int ny = y + offset[i][1];
        if (valid(nx, ny) && (map[nx][ny] == '.' || map[nx][ny] == 'D')
            && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q1.push(nx * 51 + ny);
        }
      }
    }

    step++;
  }

  printf("KAKTUS\n");
}
