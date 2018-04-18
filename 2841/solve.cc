#include <iostream>
#include <stack>

using namespace std;

int n, p;

stack<int> sts[7];

int main() {
  cin >> n >> p;

  int c = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;

    stack<int>& st = sts[a];
    if (st.empty()) {
      st.push(b);
      c++;
    }
    else {
      int v = st.top();
      if (v == b) // just shoot
        continue;
      else if (v < b) {
        st.push(b);
        c++;
      }
      else {
        while (!st.empty() && st.top() > b) {
          st.pop();
          c++;
        }

        if (st.empty()
            || st.top() != b) {
          st.push(b);
          c++;
        }
      }
    }
  }

  cout << c << "\n";
}
