#include <iostream>
#include <cstring>

using namespace std;

const int INF = 100001;

int n;
int sn;
int squares[INF];
int cache[INF];

int calc(int k) {
  if (cache[k] != -1)
    return cache[k];

  if (k == 0)
    return 0;

  int r = INF;
  for (int i = 1; i < sn; i++) {
    if (k - squares[i] < 0)
      break;
    r = min(r, calc(k - squares[i]) + 1);
  }
  cache[k] = r;
  return r;
}

int main() {
  cin >> n;
  memset(cache, -1, sizeof(cache));

  while (true) {
    if (sn * sn > 100000)
      break;
    squares[sn] = sn * sn;
    sn++;
  }
  cout << calc(n) << "\n";
}
