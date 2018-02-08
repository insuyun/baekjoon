#include <iostream>
#include <vector>

using namespace std;

vector<vector<int64_t>> cache;

#define NUM 1000000000

int64_t stair(int n, int beg) {
  if (n == 0)
    return 1;

  int value = cache[n][beg];
  if (value != -1)
    return value;

  if (beg == 9)
    value = stair(n - 1, 8);
  else if (beg == 0)
    value = stair(n - 1, 1);
  else
    value = stair(n - 1, beg + 1) + stair(n - 1, beg - 1);

  cache[n][beg] = value % NUM;
  return cache[n][beg];
}

int main() {
  int n;
  cin >> n;

  cache.resize(n);
  for (int i = 0; i < n; i++)
    cache[i].resize(10, -1);

  int sum = 0;
  for (int i = 1; i <= 9; i++)
    sum = (sum + stair(n - 1, i)) % NUM;
  cout << sum << "\n";
}
