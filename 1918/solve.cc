#include <iostream>
#include <stack>

using namespace std;

int priority(char c) {
  if (c == '(')
    return 0;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 2;
}

void update(stack<char>& st, char c) {
  while (!st.empty()) {
    char c2 = st.top();
    if (priority(c2) < priority(c))
      break;
    cout << c2;
    st.pop();
  }
  st.push(c);
}

int main() {
  string s;
  cin >> s;

  stack<char> st;

  // A*(B+C) = ABC+*
  // A+(B*C) = ABC*+

  for (char c : s) {
    if (c == '*'
        || c == '/'
        || c == '+'
        || c == '-')
      update(st, c);
    else if (c == '(')
      st.push(c);
    else if (c == ')') {
      while (!st.empty()) {
        char c2 = st.top();
        st.pop();
        if (c2 == '(')
          break;
        cout << c2;
      }
    }
    else
      cout << c;
  }

  while (!st.empty()) {
    char c = st.top();
    st.pop();
    cout << c;
  }
}
