#include <iostream>
#include <set>
#include <map>
#include <cassert>

using namespace std;

int n;
int pos[1001][2];
int num[1001][1001];
int sum[1001][1001];

int main() {
  set<int> s[2];
  map<int, int> m[2];
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> pos[i][j];
      s[j].insert(pos[i][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    int count = 0;
    for(auto x : s[i]) {
      m[i][x] = count;
      // cout << "x" << i << ":" << x << "->" << count << "\n";
      count++;
    }
  }

  // reform
  for (int i = 0; i < n; i++) {
    int x = m[0][pos[i][0]];
    int y = m[1][pos[i][1]];

    num[x][y] += 1;
    // cout << "num(" << x << ", " << y << "): " << num[x][y] << "\n";
  }

  // calculate partial sum
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + num[i][j];
      // cout << "sum(" << (i + 1) << ", " << (j + 1) << "): " << sum[i+1][j+1] << "\n";
    }
  }

  int ans = 1000000000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x1 = sum[i + 1][j + 1];
      int x2 = sum[n][j + 1] - sum[i + 1][j + 1];
      int x3 = sum[i + 1][n] - sum[i + 1][j + 1];
      int x4 = sum[n][n] - sum[n][j + 1] - sum[i + 1][n] + sum[i + 1][j + 1];

      // cerr << x1 << ", " << x2 << ", " << x3 << ", " << x4 << "\n";
      // assert(x1 + x2 + x3 + x4 == n);
      ans = min(max(max(max(x1, x2), x3) ,x4), ans);
    }
  }

  cout << ans << "\n";
}
