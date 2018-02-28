#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int kMaxVert = 20000 + 1;

vector<int> edges[kMaxVert];
int colors[kMaxVert];
int n;
int e;

bool bipartite(int u, int c) {
  if (colors[u] != -1) {
    if (colors[u] == c)
      return true;
    else
      return false;
  }

  colors[u] = c;

  for (int v : edges[u]) {
    if (!bipartite(v, (c + 1) % 2))
      return false;
  }

  return true;
}

bool bipartite_all() {
  for (int i = 1; i <= n; i++) {
    if (colors[i] == -1 && !bipartite(i, 0))
      return false;
  }

  return true;
}


int main() {
  int k;

  cin >> k;
  while (k--) {
    memset(colors, -1, sizeof(colors));

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    if (bipartite_all())
      cout << "YES\n";
    else
      cout << "NO\n";

    for (int i = 1; i <= n; i++)
      edges[i].clear();
  }
}
