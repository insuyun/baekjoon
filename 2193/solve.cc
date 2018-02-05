#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

vector<uint64_t> cache;

uint64_t pinary(int n) {
  if (n == 1)
    return 1;

  if (n == 0)
    return 1;

  if (cache[n] != -1)
    return cache[n];

  uint64_t res = 0;
  for (uint64_t i = 0; i < n-1; i++)
    res += pinary(i);
  cache[n] = res;
  return res;
}

int main() {
  int n;
  cin >> n;

  cache = vector<uint64_t>(n + 1, -1);
  cout << pinary(n) << endl;
}
