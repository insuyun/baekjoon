#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 10001

int n, m;
int k;
int money[MAX_N];
int parents[MAX_N];
int minval[MAX_N];

int findP(int s) {
  if (parents[s] < 0)
    return s;
  return parents[s] = findP(parents[s]);
}

void merge(int a, int b) {
  int pa = findP(a);
  int pb = findP(b);

  if (pa != pb)
    parents[pa] = pb;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(parents, -1, sizeof(parents));

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    cin >> money[i];

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }

  for (int i = 1; i <= n; i++) {
    int p = findP(i);
    if (minval[p] == 0)
      minval[p] = money[i];
    else
      minval[p] = min(minval[p], money[i]);
  }

  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum += minval[i];

  if (sum <= k)
    cout << sum << "\n";
  else
    cout << "Oh no\n";
}
