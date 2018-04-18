#include <iostream>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    char delim;
    string s;
    deque<int> d;

    cin >> s >> n >> delim;

    for (int i = 0; i < n; i++) {
      int v;
      cin >> v >> delim;
      d.push_back(v);
    }

    if (n == 0)
      cin >> delim;

    bool forward = true;
    bool error = false;

    for (char c : s) {
      switch (c) {
        case 'R':
          forward = !forward;
          break;

        case 'D':
          if (d.empty()) {
            error = true;
            break;
          }
          else {
            if (forward)
              d.pop_front();
            else
              d.pop_back();
          }
      }

      if (error)
        break;
    }

    if (error) {
      cout << "error\n";
    }
    else {
      cout << "[";
      bool first = true;
      while (!d.empty()) {
        if (first)
          first = false;
        else
          cout << ",";
        cout << (forward ? d.front() : d.back());
        forward ? d.pop_front() : d.pop_back();
      }
      cout << "]\n";
    }
  }
}
