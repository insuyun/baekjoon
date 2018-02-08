#include <iostream>
#include <vector>

using namespace std;

vector<int> cache;

int tile(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  if (cache[n] != -1)
    return cache[n];

  cache[n] = (tile(n - 1) + tile(n - 2)) % 10007;
  return cache[n];
}

int main() {
  int n;
  cin >> n;
  cache.resize(n + 1, -1);
  cout << tile(n) << "\n";
}
