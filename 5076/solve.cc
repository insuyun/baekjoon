#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

bool find_tag(stack<string>& st, string& tag) {
  while (!st.empty()) {
    string tag2 = st.top();
    st.pop();
    if (tag2 == tag)
      return true;
  }

  return false;
}

int main() {
  while (true) {
    stack<string> st;
    string s;
    string tag;

    bool in_tag = false;
    bool end_tag = false;
    bool error = false;
    getline(cin, s);

    if (s[0] == '#')
      break;

    for (size_t i = 0; i < s.size(); i++) {
      char c = s[i];

      if (c == '<') {
        if (s[i + 1] == '/')
          end_tag = true;
        in_tag = true;
        tag = "";
      }
      else if (c == '>') {
        in_tag = false;

        if (s[i - 1] != '/') {
          if (end_tag) {
//            cout << "END_TAG: " << tag << "\n";
            end_tag = false;
            if (!find_tag(st, tag))
              error = true;
          }
          else {
//            cout << "START_TAG: " << tag << "\n";
            st.push(tag);
          }
        }
      }
      else {
        if (in_tag && c != '/') {
          if (c == ' ')
            in_tag = false;
          else
            tag += c;
        }
      }
    }

    if (!st.empty())
      error = true;

    cout << (error ? "illegal" : "legal") << "\n";
  }
}
