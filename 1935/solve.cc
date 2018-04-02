#include <iostream>
#include <stack>
#include <vector>

using namespace std;

double value['Z' - 'A' + 1];

int main() {
  string s;

  int n;
  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++)
    cin >> value[i];

  stack<double> st;

  for (char c : s) {
    if (c == '*') {
      double f1 = st.top();
      st.pop();
      double f2 = st.top();
      st.pop();
    //  cout << c << ": " << f1 << ", " << f2 << "\n";
      st.push(f1 * f2);
    }
    else if (c == '+') {
      double f1 = st.top();
      st.pop();
      double f2 = st.top();
      st.pop();
   //  cout << c << ": " << f1 << ", " << f2 << "\n";
      st.push(f1 + f2);
    }
    else if (c == '-') {
      double f1 = st.top();
      st.pop();
      double f2 = st.top();
      st.pop();
   //   cout << c << ": " << f1 << ", " << f2 << "\n";
      st.push(f2 - f1);
    }
    else if (c == '/') {
      double f1 = st.top();
      st.pop();
      double f2 = st.top();
  //    cout << c << ": " << f1 << ", " << f2 << "\n";
      st.pop();
      st.push(f2 / f1);
    }
    else {
      st.push(value[c - 'A']);
    }
  }

//  cout << st.size() << "\n";
  printf("%.2f\n", st.top());

}
