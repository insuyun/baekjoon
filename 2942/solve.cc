#include <iostream>

using namespace std;

int64_t r, g;

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  cin >> r >> g;
  int64_t d = gcd(r, g);
  for (int i = 1; i <= d; i++)
    if ((r % i) == 0 && g  % i == 0)
      cout << i << " " << r / i << " " << g / i << "\n";
}
