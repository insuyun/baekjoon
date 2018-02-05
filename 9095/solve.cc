#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(12, -1);

int solve(int n) {
  if (n == 1)
    return 1;

  if (n == 2)
    return 2;

  if (n == 3)
    return 4;

  if (cache[n] != -1)
    return cache[n];

  cache[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
  return cache[n];
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
