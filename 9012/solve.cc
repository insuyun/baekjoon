#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    bool valid = true;
    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
      if (c == '(')
        st.push('(');
      else if (c == ')') {
        if (st.empty())
          valid = false;
        else {
          st.pop();
        }
      }
    }

    if (!st.empty())
      valid = false;

    cout << (valid ? "YES" : "NO") << "\n";
  }
}
