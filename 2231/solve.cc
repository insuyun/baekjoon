#include <iostream>

using namespace std;

int decompose(int i) {
  int sum = i;
  while (i != 0)  {
    sum += i % 10;
    i /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    int decomposed = decompose(i);
    if (decomposed == n) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "0\n";
}
