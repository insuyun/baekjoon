#include <iostream>

using namespace std;

int n, m;
int num[100001];
int sum[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  num[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    sum[i] = num[i] + sum[i - 1];
  }

  while(m--) {
    int i, j;
    cin >> i >> j;
    cout << sum[j] - sum[i - 1] << "\n";
  }
}
