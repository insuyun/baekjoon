#include <iostream>
#include <vector>

using namespace std;

bool has[51];

int limit;

int find_max(int len) {
  int c_len = 0;
  int i = 1;

  while (true) {
    c_len += (i >= 10) ? 2 : 1;
    if (len == c_len)
      return i;
    i++;
  }
}

void find_perm(vector<int>& perm, std::string& s, int index) {
  if (index == s.size()) {
    for (auto x : perm)
      cout << x << " ";
    cout << "\n";
    exit(0);
  }

  const int offset[2] = {1, 2};
  for (int i = 0; i < 2; i++) {
    if (index + offset[i] <= s.size()) {
      std::string ss = s.substr(index, offset[i]);
      int n = stoi(ss);
      if (n <= limit && n > 0 && !has[n]) {
        has[n] = true;
        perm.push_back(n);
        find_perm(perm, s, index + offset[i]);
        perm.pop_back();
        has[n] = false;
      }
    }
  }
}

int main() {
  std::string s;
  cin >> s;
  vector<int> perm;
  limit = find_max(s.size());
  find_perm(perm, s, 0);
}
