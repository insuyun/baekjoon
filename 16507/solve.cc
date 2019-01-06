#include <iostream>

using namespace std;

int r, c, q;
int light[1001][1001];
int sum[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c >> q;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> light[i][j];
      // calcualte sum
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + light[i][j];
    }
  }

  while(q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int num = (r2 - r1 + 1) * (c2 - c1 + 1);
    // cout << sum[r2 + 1][c2 + 1] << ", "
    //      << sum[r1][c2 + 1] << ", "
    //      << sum[r2 + 1][c1] << ", "
    //      << sum[r1][c1] << "\n";
    cout << ((sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] + sum[r1][c1]) / num) << "\n";
  }
}
