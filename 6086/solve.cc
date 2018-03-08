#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int kMax = 256;

int cap[kMax][kMax];
int flow[kMax][kMax];
int parent[kMax];

int dfs(int u) {
  // cout << "u: " << u << "\n";
  for (int i = 0; i < kMax; i++) {
    if (cap[u][i] != 0
        && parent[i] == -1) {
      // cout << "u: " << u << ", i: " << i << ", cap[u][i]: " << cap[u][i] << "\n";
      parent[i] = u;
      dfs(i);
    }
  }
}


int main() {
  int n;
  cin >> n;
  while (n--) {
    char a, b;
    int f;

    cin >> a >> b >> f;
    cap[a][b] += f;
  }

  // Run DFS
  while (true) {
    memset(parent, -1, sizeof(parent));
    parent['A'] = 0;
    dfs('A');
    parent['A'] = -1;

    if (parent['Z'] == -1)
      break;
    // Find a minimum cost along the path
    int mc = 2000;
    int n = 'Z';

    while (parent[n] != -1) {
      // cout << "n: " << (char)n << "\n";
      mc = min(cap[parent[n]][n], mc);
      n = parent[n];
    }

    n = 'Z';
    while (parent[n] != -1) {
      cap[parent[n]][n] -= mc;
      cap[n][parent[n]] += mc;
      n = parent[n];
    }
    assert(mc != 0);
    // cout << mc << "\n";
  }

  int v = 0;
  for (int i = 0; i < kMax; i++)
    v+= cap[i]['A'];
  cout << v << "\n";
}
