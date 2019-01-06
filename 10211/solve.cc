#include <iostream>
#include <climits>

using namespace std;

int t, n;
int sum[1002];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      sum[i + 1] = sum[i] + num;
    }

    int maxVal = INT_MIN;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        maxVal = max(maxVal, sum[i + 1] - sum[j]);
      }
    }

    cout << maxVal << "\n";
  }
}
