#include <iostream>
#include <list>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    list<char> l;
    list<char>::iterator it = l.begin();

    for (char c : s) {
      if (c == '<') {
        if (it != l.begin())
          it--;
      }
      else if (c == '>') {
        if (it != l.end())
          it++;
      }
      else if (c == '-') {
        if (it != l.begin()) {
          it--;
          it = l.erase(it);
        }
      }
      else {
        l.insert(it, c);
      }
    }
    for (char c : l)
      cout << c;
    cout << "\n";

  }
}
