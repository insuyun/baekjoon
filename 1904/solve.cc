#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 15746;
const int MAX = 1000000;

int tile(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;

  int a = 1;
  int b = 2;
  int c = 0;

  for (int i = 2; i < n; i++) {
    c = (a + b) % MOD;
    a = b;
    b = c;
  }

  return c;
}

int main() {
  int n;
  cin >> n;
  cout << tile(n) << "\n";
}
