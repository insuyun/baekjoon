#include <iostream>

using namespace std;

int n, r, c;
int counter, res;

void z(int x, int y, int size) {
  //printf("x=%d y=%d r=%d c=%d size=%d\n", x, y, r, c,size);
  if (size == 1) {
    if (x == r && y == c)
      res = counter;
    counter++;
    return;
  }

  if (x + size < r) {
    counter += size * size;
    return;
  }

  if (y + size < c) {
    counter += size * size;
    return;
  }

  if (res != 0)
    return;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      z(x + size / 2 * i, y + size / 2 * j, size / 2);
    }
  }
}

int main() {
  cin >> n >> r >> c;
  z(0, 0, 1 << n);
  cout << res << "\n";
}
