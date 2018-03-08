#include <iostream>

using namespace std;

int num[10];

int main() {
  int n;
  cin >> n;

  while (n != 0) {
    int r = n % 10;
    num[r]++;
    n /= 10;
  }

  int m = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9)
      break;
    m = max(m, num[i]);
  }

  m = max(m, (num[6] + num[9] + 1) / 2);

  if (m == 0)
    cout << "1\n";
  else
    cout << m << "\n";
}
