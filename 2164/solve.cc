#include <iostream>
#include <queue>

using namespace std;

int main() {
  deque<int> q;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    q.push_back(i);
  }

  while (q.size() != 1) {
    q.pop_front();
    int card = q.front();
    q.pop_front();
    q.push_back(card);
  }

  cout << q.front() << "\n";
}
