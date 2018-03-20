#include <iostream>
#include <cassert>

using namespace std;

const int kMax = 101;

int n;
int guess[kMax];
int strike[kMax];
int ball[kMax];

pair<int, int> calculate(int x, int y, int z, int v) {
  int n_strike = 0;
  int n_ball = 0;
  int p[3] = {x, y, z};
  int div = 100;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (v / div % 10 == p[j]) {
        if (i == j)
          n_strike++;
        else {
          // cout << v << ", " << i << ", " << j << "\n";
          n_ball++;
        }
      }
    }
    div /= 10;
  }

  return make_pair(n_strike, n_ball);
}

bool check(int x, int y, int z) {
  for (int i = 0; i < n; i++) {
    pair<int, int> p = calculate(x, y, z, guess[i]);
    if (p.first != strike[i] || p.second != ball[i]) {
      return false;
    }
  }
  return true;
}

int count() {
  int c = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = 1; k <= 9; k++) {
        if (i == j || j == k || k == i)
          continue;

        // cout << i << j << k << "\n";
        if (check(i, j, k))
          c++;
      }
    }
  }
  return c;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> guess[i] >> strike[i] >> ball[i];

  cout << count() << "\n";

#if 0

  pair<int, int> p = calculate(3, 2, 4, 123);
  assert(p.first == 1 && p.second == 1);
  p = calculate(3, 2, 4, 356);
  assert(p.first == 1 && p.second == 0);
#endif
}
