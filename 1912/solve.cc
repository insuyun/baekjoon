#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main() {
  int max_local = -1000;
  int max_global = -1000;
  int value = 0;

  ios_base::sync_with_stdio(false);
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> value;
    max_local = max(max_local + value, value);
    max_global = max(max_global, max_local);
  }
  cout << max_global << "\n";
}
