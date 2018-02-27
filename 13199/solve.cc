#include <iostream>

using namespace std;

int main() {
  int64_t t, p, m, f, c;
  cin >> t;
  while (t--) {
    cin >> p >> m >> f >> c;
    int64_t a = (m / p) + ((m / p) * c  / f);
    int64_t b = m / p;
    int64_t bc = (m / p) * c;
    while (bc >= f) {
      b += bc / f;
      bc = bc - (bc / f) * f + (bc / f) * c;
    }
    cout << b - a << "\n";
  }
}
