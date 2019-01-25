#include <iostream>
#include <map>

using namespace std;
map<int64_t, int64_t> m;
int64_t n, p, q;

int64_t inf(int64_t x) {
  if (x == 0)
    return 1;
  if (m.find(x) != m.end())
    return m[x];
  int64_t r = inf(x / p) + inf(x / q);
  m[x] = r;
  return r;
}

int main() {
  cin >> n >> p >> q;
  cout << inf(n) << "\n";
}
