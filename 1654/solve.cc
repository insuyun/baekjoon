#include <iostream>
#include <limits.h>

using namespace std;

const int MAX = 1000001;
int k, n;
int64_t lengths[MAX];


int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++)
    cin >> lengths[i];

  int64_t lo = 0;
  int64_t hi = (int64_t)INT_MAX + 1;

  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) / 2;
    int64_t num = 0;
    for (int64_t i = 0; i < k; i++)
      num += lengths[i] / mid;

    if (num >= n)
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << "\n";
}
