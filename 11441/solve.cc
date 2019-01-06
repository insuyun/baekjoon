#include <iostream>
#include <stdint.h>
using namespace std;

typedef int64_t i64;

i64 n, m;
i64 sum[100002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    i64 num;
    cin >> num;
    sum[i + 1] = sum[i] + num;
  }

  cin >> m;
  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << sum[j + 1] - sum[i] << "\n";
  }
}
