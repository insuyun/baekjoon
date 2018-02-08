#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> wine;

  for (int i = 0; i < n; i++) {
    int v = 0;
    cin >> v;
    wine.push_back(v);
  }

  int cum[n + 1][3];
  cum[0][0] = 0;
  cum[0][1] = 0;
  cum[0][2] = 0;

  for (int i = 1; i <= n; i++) {
    cum[i][0] = max(max(cum[i-1][0], cum[i-1][1]), cum[i-1][2]);
    cum[i][1] = cum[i-1][0] + wine[i - 1];
    cum[i][2] = cum[i-1][1] + wine[i - 1];

//    cout << cum[i][0] << ", " << cum[i][1] << ", " << cum[i][2] << "\n";
  }

  cout << max(max(cum[n][0], cum[n][1]), cum[n][2]) << "\n";
}
