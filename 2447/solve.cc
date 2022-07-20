#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

#define MAX_N 2187

int N;
char stars[MAX_N + 1][MAX_N + 1];

void make_star(int x, int y, int size) {
  if (size == 1) {
    stars[x][y] = '*';
    return;
  }

  assert(size % 3 == 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1)
        continue;
      make_star(x + size / 3 * i, y + size / 3 * j, size / 3);
    }
  }
}

int main() {
  cin >> N;
  memset(stars, ' ', sizeof(stars));
  make_star(0, 0, N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << stars[i][j];
    }
    cout << "\n";
  }
}
