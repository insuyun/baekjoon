#include <iostream>

using namespace std;

int64_t n, k;
int main() {
  cin >> n >> k;

  int64_t lo = 0;
  int64_t hi = 10000000000 + 1;

  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) / 2;
    int64_t sum = 0;

    for (int64_t i = 1; i <= n; i++) {
      int64_t lo2 = 0;
      int64_t hi2 = n + 1;

      while (lo2 + 1 < hi2) {
        int64_t mid2 = (lo2 + hi2) / 2;
        if (i * mid2 <= mid)
          lo2 = mid2;
        else
          hi2 = mid2;
      }
      sum += lo2;
//      cout << "lo2: " << lo2 << "\n";
    }

    // (lo, hi]
    if (sum < k)
      lo = mid;
    else
      hi = mid;
//    cout << "mid: " << mid << ", sum: " << sum << "\n";
  }

  cout << hi << "\n";
}
