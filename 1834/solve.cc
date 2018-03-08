#include <iostream>

using namespace std;

int n;

int main() {
  cin >> n;
  uint64_t sum = 0;
  for (int i = 0; i < n; i++) {
    sum += i * n + i;
  }
  cout << sum << "\n";
}
