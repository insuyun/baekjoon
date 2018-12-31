#include <iostream>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

#define MAX 1000000000

int n, p;
int weight[16][16];
int cache[1<<16];

int dfs(int on) {
  int &ret = cache[on];
  if (ret != -1)
    return ret;

  if (__builtin_popcount(on) == p)
    return 0;

  ret = MAX;
  for (int i = 0; i < n; i++) {
    if (!(on & (1 << i))) {
      for (int j = 0; j < n; j++) {
        if (on & (1 << j))
          ret = min(ret, dfs(on | (1 << i)) + weight[j][i]);
      }
    }
  }

  return ret;
}

int main() {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> weight[i][j];
    }
  }

  int on = 0, nOn = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'Y') {
      on |= (1 << i);
      nOn++;
    }
//    else if (c != 'N')
//      assert(false);
  }

  cin >> p;

  if (nOn >= p) {
    cout << "0\n";
    exit(0);
  }

  int res = dfs(on);
  if (res >= MAX)
    cout << "-1" << "\n";
  else
    cout << dfs(on) << "\n";
}
