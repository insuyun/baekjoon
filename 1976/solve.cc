#include <iostream>
#include <cstring>

#define MAX_N 201

using namespace std;
int n, m;

int parents[MAX_N];

int findP(int s) {
  if (parents[s] < 0)
    return s;
  return parents[s] = findP(parents[s]);
}

int merge(int a, int b) {
  int pa = findP(a);
  int pb = findP(b);

  if (pa != pb) {
    parents[pa] = pb;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  memset(parents, -1, sizeof(parents));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      bool b;
      cin >> b;
      if (b) {
        merge(i, j);
      }
    }
  }

  int parent = 0;
  for (int i = 1; i <= m; i++) {
    int c;
    cin >> c;

    // cout << parent << "\n";

    if (parent == 0)
      parent = findP(c);
    else {
      if (parent != findP(c)) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  cout << "YES\n";
}
