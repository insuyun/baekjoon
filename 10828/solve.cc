#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
  int n;
  string s;
  stack<int> st;

  cin >> n;
  while (n--) {
    cin >> s;
    if (s == "push") {
      int v;
      cin >> v;
      st.push(v);
    }
    else if (s == "pop") {
      if (st.empty()) {
        cout << "-1\n";
      }
      else {
        cout << st.top() << "\n";
        st.pop();
      }
    }
    else if (s == "size")  {
      cout << st.size() << "\n";
    }
    else if (s == "empty") {
      cout << st.empty() << "\n";
    }
    else if (s == "top") {
      if (st.empty())
        cout << "-1\n";
      else
        cout << st.top() << "\n";
    }
    else {
      assert(false);
    }
  }
}
