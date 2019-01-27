#include <iostream>
#include <queue>
#include <stdint.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  priority_queue<int64_t> pq;
  cin >> n;
  while(n--) {
    int64_t x;
    cin >> x;
    if (x) pq.push(-x);
    else if (pq.empty()) cout << "0\n";
    else {
      cout << (-pq.top()) << "\n";
      pq.pop();
    }
  }
}
