#include <iostream>

using namespace std;

int64_t heights[1000001];
int64_t n, m;

int64_t compute(int64_t s, int64_t e) {
  //cout << "compute: s=" << s << ", e=" << e << "\n";
  if (s + 1 == e)
    return s;

  int64_t mid = (s + e) / 2;
  int64_t sum = 0;
  for (int64_t i = 0; i < n; i++) {
    if (mid < heights[i])
      sum += heights[i] - mid;
  }

  //cout << "sum=" << sum << ", m=" << m << "\n";

  if (sum >= m)
    return compute(mid, e);
  else
    return compute(s, mid);
}

int main() {
  cin >> n >> m;
  int64_t m = 0;
  for (int64_t i = 0; i < n; i++) {
    cin >> heights[i];
    m = max(m, heights[i]);
  }

  cout << compute(0, m + 1) << "\n";
}
