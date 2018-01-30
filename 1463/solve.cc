#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 1000000
int cache[MAX + 1];

int run(int n) {
  for (int i = 2; i <= n; i++) {
    int num = cache[i - 1] + 1;
    if (i % 3 == 0)
      num = min(cache[i / 3] + 1, num);
    if (i % 2 == 0)
      num = min(cache[i / 2] + 1, num);
    cache[i] = num;
  }

  return cache[n];
}

int main() {
  int n;
  cin >> n;

  cache[0] = 0;
  cache[1] = 0;
  cache[2] = 1;

  cout << run(n) << "\n";
}
