#include <iostream>

using namespace std;

int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;

  int64_t r = 1;
  while (b != 0) {
    if (b % 2 == 1)
      r = (r * a) % c;
//    cout << r << "\n";
    a = (a * a) % c;
    b /= 2;
  }

  cout << r << "\n";
}
