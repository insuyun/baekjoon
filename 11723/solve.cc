#include <iostream>
#include <cassert>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  cin >> m;
  int S = 0;

  for (int i = 0; i < m; i++) {
    string cmd;
    int arg;

    cin >> cmd;

    if (cmd == "add") {
      cin >> arg;
      S |= (1 << arg);
    }
    else if (cmd == "check") {
      cin >> arg;
      if ((S & (1 << arg)))
        cout << "1\n";
      else
        cout << "0\n";
    }
    else if (cmd == "remove") {
      cin >> arg;
      S &= ~(1 << arg);
    }
    else if (cmd == "toggle") {
      cin >> arg;
      S ^= (1 << arg);
    }
    else if (cmd == "all") {
      S = ~0;
    }
    else if (cmd == "empty") {
      S = 0;
    }
    else
      assert(0);
  }
}
