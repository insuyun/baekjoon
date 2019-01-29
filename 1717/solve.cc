#include <iostream>
#include <cstring>

using namespace std;
int n, m;

int p[1000001];

int ufind(int a) {
  if (p[a] < 0) {
    return a;
  }
  p[a] = ufind(p[a]);
  return p[a];
}

void umerge(int a, int b) {
  int pa = ufind(a);
  int pb = ufind(b);
  if (pa != pb)
    p[b] = pa;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  while (m--) {
    int c, a, b;
    cin >> c >> a >> b;
    if (c == 0) {
      umerge(a, b);
    }
    else {
      // cout << ufind(a) << ", " << ufind(b) << "\n";
      if (ufind(a) == ufind(b))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
