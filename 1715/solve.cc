#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  priority_queue<int> pq;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    pq.push(-x);
  }

  int sum = 0;

  while (pq.size() != 1) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    pq.push(x+y);
    sum += (x + y);
  }

  cout << -sum<< "\n";
}
