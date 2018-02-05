#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> values(n);
  vector<vector<int>> sum(n);

  for (int i = 0; i < n; i++) {
    values[i] = vector<int>(n, 0);
    sum[i] = vector<int>(n, 0);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      int v;
      cin >> v;
      values[i][j] = v;
    }
  }

  for (int i = 0; i < n; i++)
    sum[n - 1][i] = values[n - 1][i];

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < i + 1; j++) {
      sum[i][j] = max(sum[i + 1][j] + values[i][j],
          sum[i + 1][j + 1] + values[i][j]);
    }
  }

  cout << sum[0][0] << endl;
}
