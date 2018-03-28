#include <iostream>

using namespace std;

const int MAX = 100001;

int n, m;
int money[MAX];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> money[i];

  int lo = 0;
  int hi = 1000000000 + 1;

  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    int remainder = 0;
    int count = 0;
    bool cannot = false;

    for (int i = 0; i < n; i++) {
      if (remainder < money[i]) {
        remainder = mid;
        count++;
        if (remainder < money[i])
          cannot = true;
        else
          remainder -= money[i];
      }
      else
        remainder -= money[i];
    }

    if (cannot || count > m)
      // cannot do it with mid
      lo = mid;
    else
      hi = mid;
  }
  cout << hi << "\n";
}
