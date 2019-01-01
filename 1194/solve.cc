#include <iostream>
#include <cstring>

#define MAX 1000000000
using namespace std;

int n, m;
char maze[50][50];
int offsets[4][2] = {
  1, 0,
  -1, 0,
  0, 1,
  0, -1
};

int cache[50][50][1 << ('F' - 'A' + 1)];

int search(int x, int y, int keys) {
  if (maze[x][y] == '1')
    return 0;

  if (maze[x][y] == '#')
    return MAX;

  for (char key = 'a'; key <= 'f'; key++) {
    if (maze[x][y] == key)
      keys |= (1 << (key - 'a'));
  }

  for (char key = 'A'; key <= 'F'; key++) {
    if (maze[x][y] == key && !(keys & (1 << (key - 'A'))))
      return MAX;
  }

  // cout << "x: " << x << ", y: " << y << ", keys: " << keys << "\n";

  int &ret = cache[x][y][keys];
  if (ret != -1)
    return ret;

  ret = MAX;
  for (int i = 0; i < 4; i++) {
    int nextX = x + offsets[i][0];
    int nextY = y + offsets[i][1];

    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
      continue;

    ret = min(1 + search(nextX, nextY, keys), ret);
  }

  return ret;
}

int main() {
  memset(cache, -1, sizeof(cache));
  int startX, startY;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '0') {
        startX = i;
        startY = j;
      }
    }
  }

  //cout << startX << ", " << startY << "\n";
  int ret = search(startX, startY, 0);
  if (ret == MAX)
    cout << "-1\n";
  else
    cout << ret << "\n";
}
