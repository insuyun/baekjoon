#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int cache[1001][1001];

int comb(int n, int k) {
  if (n == k)
    return 1;
  if (k == 0)
    return 1;

  if (cache[n][k] == -1) {
    cache[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % 10007;
  }
  return cache[n][k];
}

int main() {
  memset(cache, -1, sizeof(cache));
  cin >> n >> k;
  cout << comb(n, k) << "\n";
}
