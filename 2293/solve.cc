#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> coins;
  coins.push_back(0);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    coins.push_back(c);
  }

  vector<vector<int>> counts;
  for (int i = 0; i < k + 1; i++) {
    counts.push_back(vector<int>(n + 1, 0));
  }

  for (int i = 0; i <= n; i++)
    counts[0][i] = 1;

  for (int i = 1; i <= k; i++){
    for (int j = 1; j <= n; j++) {
      counts[i][j] = counts[i][j - 1];

      if (i - coins[j] >= 0)
        counts[i][j] += counts[i - coins[j]][j];
      // cout << i << ", " << j << ": " << counts[i][j] << "\n";
    }
  }


  cout << counts[k][n] << "\n";
}
