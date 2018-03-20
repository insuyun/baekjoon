#include <iostream>

using namespace std;

int64_t l, p, v;

int main() {
  int64_t i = 1;
  while (true) {
    cin >> l >> p >> v;
    if (l == 0 && p == 0 && v == 0)
      break;
    cout << "Case " << i << ": " << (v / p * l + min(v % p, l)) << "\n";
    i++;
  }
}
