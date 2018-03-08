#include <iostream>
#include <cstring>

using namespace std;

int b[1001];
int w[1001];

int n;

int cache[1001][30][30];

int compute(int i, int x, int y) {
  if (i == -1)
    return 0;

  if (cache[i][x][y] != -1)
    return cache[i][x][y];

  int r = compute(i - 1, x, y);
  if (x != 0)
    r = max(r, compute(i - 1, x - 1, y) + b[i]);
  if (y != 0)
    r = max(r, compute(i - 1, x, y - 1) + w[i]);
  cache[i][x][y] = r;
  return r;
}

int main() {
  memset(cache, -1, sizeof(cache));
  while (true) {
    int x = 0, y = 0;
    cin >> x >> y;
    if (x == 0 && y == 0)
      break;
    b[n] = x;
    w[n] = y;
    n++;
  }

  cout << compute(n - 1, 15, 15) << "\n";
}
