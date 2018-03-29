#include <iostream>
#include <list>

using namespace std;

int n;

int main() {
  list<char> l;
  string s;
  getline(cin, s);

  cin >> n;
  list<char>::iterator it = l.end();

  for (int i = 0; i < s.size(); i++)
    l.push_back(s[i]);

  while (n--) {
    char cmd;
    cin >> cmd;

    if (cmd == 'L') {
      if (it != l.begin())
        it--;
    }
    else if (cmd == 'D') {
      if (it != l.end())
        it++;
    }
    else if (cmd == 'B') {
      if (it != l.begin()) {
        list<char>::iterator tmp = it;
        it--;
        l.erase(it);
        it = tmp;
      }
    }
    else if (cmd == 'P') {
      char t;
      cin >> t;
      l.insert(it, t);
    }
  }

  for (char c : l)
    cout << c;
  cout << "\n";
}
