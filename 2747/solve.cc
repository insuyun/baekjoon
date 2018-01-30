#include <iostream>
#include <cstdio>
#include <stdint.h>

using namespace std;

uint64_t fibo(int n) {
  uint64_t arr[3];
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i < n; i++) {
    arr[i % 3] = arr[(i - 1) % 3]  + arr[(i - 2) % 3];
  }
  return arr[(n - 1) % 3];
}

int main() {
  uint64_t n;
  cin >> n;
  cout << fibo(n+1) << "\n";
}
