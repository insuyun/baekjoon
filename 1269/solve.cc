#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, m;
  set<int> a, b;
  set<int> result;

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }

  int r = 0;
  set_difference(a.begin(), a.end(), b.begin(), b.end(), std::inserter(result, result.end()));
  set_difference(b.begin(), b.end(), a.begin(), a.end(), std::inserter(result, result.end()));
  cout << result.size() << "\n";
}
