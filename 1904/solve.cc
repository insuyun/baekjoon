#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 15746;
const int MAX = 1000000;
int cache[MAX];

int tile(int n) {
  if (cache[n] != -1)
    return cache[n];

  if (n == 1)
    return 1;

  if (n == 2)
    return 2;

  int r = (tile(n - 1) + tile(n - 2)) % MOD;
  cache[n] = r;
  return cache[n];
}

int main() {
  int n;
  memset(cache, -1, sizeof(cache));
  cin >> n;
  cout << tile(n) << "\n";
}
