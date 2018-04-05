#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  int n = 0;

  while (t--) {
    stack<char> st;
    string s;
    cin >> s;
    for (char c : s) {
      if (st.empty()) {
        st.push(c);
      }
      else {
        if (st.top() == c)
          st.pop();
        else
          st.push(c);
      }
    }

    if (st.empty())
      n++;
  }

  cout << n << "\n";
}
