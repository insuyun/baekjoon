#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000000

int n;

int cache[100][10][1<<10];

int dfs(int len, int lastNum, int used) {
  if (len == n) {
    // cout << used << "\n";
    if (used == ((1 << 10) - 1))
      return 1;
    else
      return 0;
  }

  // cout << len << ", " << lastNum << ", " << used << "\n";
  int &ret = cache[len][lastNum][used];
  if (ret != -1)
    return ret;

  ret = 0;
  if (lastNum == 0) {
    ret += dfs(len + 1, 1, used | (1 << 1));
//    ret += dfs(len + 1, 9, used | (1 << 9)); // ??
  }
  else if (lastNum == 9) {
    ret += dfs(len + 1, 8, used | (1 << 8));
//    ret += dfs(len + 1, 0, used | (1 << 0));
  }
  else {
    ret += dfs(len + 1, lastNum - 1, used | (1 << (lastNum - 1)));
    ret += dfs(len + 1, lastNum + 1, used | (1 << (lastNum + 1)));
  }
  ret = ret % MOD;

  // cout << "dfs(" << len << ", " << lastNum << "): " << ret << "\n";

  return ret;
}

int main() {
  memset(cache, -1, sizeof(cache));
  cin >> n;

  int sum = 0;
  for (int i = 1; i < 10; i++) {
    sum = (sum + dfs(1, i, (1 << i))) % MOD;
  }

  cout << sum << "\n";
}
