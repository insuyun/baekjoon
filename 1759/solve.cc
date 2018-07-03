#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> chars;
bool moum[256];

void print(vector<char>& pass) {
  for (auto x : pass)
    cout << x;
}

void brute(vector<char>& pass, int idx, int nm, int nz) {
#if 0
  cout << "pass: ";
  print(pass);
  cout << ", idx: " << idx << ", nm: " << nm << ", nz: " << nz << "\n";
#endif
  if (pass.size() == l) {
    if (nm >= 1 && nz >= 2) {
      print(pass);
      cout << "\n";
    }
    return;
  }

  if (idx == chars.size())
    return;

  pass.push_back(chars[idx]);
  int next_nm = nm + moum[chars[idx]];
  int next_nz = nz + !moum[chars[idx]];
  brute(pass, idx + 1, next_nm, next_nz);
  pass.pop_back();

  brute(pass, idx + 1, nm, nz);
}

int main() {

  moum['a'] = true;
  moum['i'] = true;
  moum['e'] = true;
  moum['o'] = true;
  moum['u'] = true;

  cin >> l >> c;
  for (int i = 0; i < c; i++) {
    char ch;
    cin >> ch;
    chars.push_back(ch);
  }

  sort(chars.begin(), chars.end());

  vector<char> pass;
  brute(pass, 0, 0, 0);
}
