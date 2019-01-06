#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t sum[1000001];
uint64_t count[1000];
uint64_t n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    sum[i + 1] = (sum[i] + num) % m;
  }

  for (int i = 0; i <= n; i++) {
    count[sum[i]] += 1;
  }

  uint64_t total = 0;
  for (int i = 0; i < m; i++) {
    total += count[i] * (count[i] - 1) / 2;
  }

  cout << total << "\n";
}
