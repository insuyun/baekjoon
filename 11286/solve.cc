#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  while (n--) {
    int x;
    cin >> x;

    if (x) {
      if (x < 0)
        pq.push(make_pair(x, -x));
      else
        pq.push(make_pair(-x, -x));
    }
    else if (pq.empty())
      cout << "0\n";
    else {
      pair<int, int> p = pq.top();
      pq.pop();
      cout << -p.second << "\n";
    }
  }
}
