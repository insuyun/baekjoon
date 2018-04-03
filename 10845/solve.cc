#include <iostream>
#include <queue>

using namespace std;

int main() {
  deque<int> q;
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    if (s == "push") {
      int v;
      cin >> v;
      q.push_back(v);
    }
    else if (s == "front")
      cout << (q.empty() ? -1 : q.front()) << "\n";
    else if (s == "size")
      cout << q.size() << "\n";
    else if (s == "back")
      cout << (q.empty() ? -1 : q.back()) << "\n";
    else if (s == "empty")
      cout << q.empty() << "\n";
    else if (s == "pop") {
      cout << (q.empty() ? -1 : q.front()) << "\n";
      if (!q.empty()) q.pop_front();
    }
  }
}
