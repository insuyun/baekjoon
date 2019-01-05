#include <iostream>
#include <climits>

using namespace std;

int n, m;

int xored[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  xored[0] = 0;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    xored[i] = xored[i - 1] ^ num;
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    ans ^= (xored[e] ^ xored[s-1]);
    // cout << xored[e] << ", " << xored[s-1] << "\n";
    // cout << (xored[e] ^ xored[s-1]) << "\n";
  }

  cout << ans << "\n";
}
