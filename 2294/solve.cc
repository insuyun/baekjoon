#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 101;
const int INF = 10001;

int n, k;
int coins[MAX];
int cache[INF];

int calc(int v) {
  if (cache[v] != -1)
    return cache[v];
  if (v == 0)
    return 0;

  int r = INF;
  for (int i = 0; i < n; i++) {
    if (v - coins[i] >= 0)
      r = min(r, calc(v - coins[i]) + 1);
  }
  cache[v] = r;
  return r;
}

int main() {
  cin >> n >> k;
  memset(cache, -1, sizeof(cache));
  for (int i = 0; i < n;  i++)
    cin >> coins[i];
  int r = calc(k);
  if (r == INF)
    cout << "-1\n";
  else
    cout << r << "\n";
}
