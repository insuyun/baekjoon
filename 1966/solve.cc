#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    int res;
    cin >> n >> m;
    vector<int> v;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      int imp;
      cin >> imp;
      q.push(make_pair(imp, i));
      v.push_back(imp);
    }

    sort(v.begin(), v.end());

    while (!q.empty()) {
      pair<int, int> x = q.front();
      q.pop();
      if (x.first != v.back())
        q.push(x);
      else {
        if (x.second == m)
          res = n - q.size();
        v.pop_back();
      }
    }

    cout << res << "\n";
  }
}
