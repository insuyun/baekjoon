#include <iostream>

using namespace std;
const int MOD = 10007;

int main() {
  int n;
  cin >> n;

  int f_1 = 1;
  int f_2 = 1;
  int f = f_1;

  for (int i = 1; i < n; i++) {
    f = (f_1 + 2 * f_2) % MOD;
    f_2 = f_1;
    f_1 = f;
  }

  cout << f << "\n";
}
