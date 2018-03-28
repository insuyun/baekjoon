#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
const int MAX = 200000;

int n, c;
int pos[MAX];
int diff[MAX];

int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> pos[i];

  sort(pos, pos + n);
  for (int i = 0; i < n - 1; i++) {
    diff[i] = pos[i + 1] - pos[i];
//    cout << "diff:" << diff[i] << "\n";
  }

  int64_t lo = 0;
  int64_t hi = INT_MAX;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) / 2;
    int64_t sum = 0;
    int64_t count = 1;
    bool cannot = false;

    for (int i = 0; i < n - 1; i++) {
      if (sum + diff[i] >= mid) {
        sum = 0;
        count++;
      }
      else
        sum += diff[i];
    }

//    cout << "cannot: " << cannot << "\n";
//    cout << "lo: " << lo << ", hi: " << hi << ", count: " << count << "\n";
    if (c > count)
      hi = mid;
    else
      lo = mid;
  }

  cout << lo << "\n";
}
