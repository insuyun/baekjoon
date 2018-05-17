#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int cell[3][3];

int offset[4][2] = {
  1, 0,
  -1, 0,
  0, 1,
  0, -1
};

int get_hash() {
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      n *= 10;
      n += cell[i][j];
    }
  }
  return n;
}

void recover(int h) {
  for (int i = 2; i >= 0; i--) {
    for (int j = 2; j >= 0; j--) {
      cell[i][j] = h % 10;
      h /= 10;
    }
  }
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> cell[i][j];
    }
  }

  queue<int> q;
  unordered_map<int, bool> visited;

  int h = get_hash();
  visited[h] = true;
  q.push(h);

  int step = 0;
  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      int h = q.front();

      if (h == 123456780) {
        printf("%d\n", step);
        return 0;
      }

      q.pop();
      recover(h);

      // Find zero
      int zx, zy;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (cell[i][j] == 0) {
            zx = i;
            zy = j;
          }
        }
      }

      for (int i = 0; i < 4; i++) {
        int nx = zx + offset[i][0];
        int ny = zy + offset[i][1];

        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
          // printf("prev_h: %09d\n", get_hash());
          int num = cell[nx][ny];
          cell[zx][zy] = num;
          cell[nx][ny] = 0;
          // printf("(%d, %d) -> (%d, %d)\n", zx, zy, nx, ny);
          // printf("next_h: %09d\n", get_hash());

          int h = get_hash();
          if (visited.find(h) == visited.end()) {
            visited[h] = true;
            q.push(h);
          }

          // recover
          cell[nx][ny] = num;
          cell[zx][zy] = 0;
        }
      }
    }

    step++;
  }

  printf("-1\n");
}
