#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> depths;
vector<vector<int>> children;
int root;

void dfs(int node, int depth) {
  depths[node] = depth;

  for (int child : children[node])
    dfs(child, depth + 1);
}

void solve() {
  int n;
  cin >> n;

  parents = vector<int>(n + 1, 0);
  depths = vector<int>(n + 1, 0);
  children = vector<vector<int>>(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    parents[b] = a;
    children[a].push_back(b);
  }

  // Find a root node
  for (int i = 1; i <= n; i++)
    if (parents[i] == 0)
      root = i;

  // cout << "Root node: " << root << "\n";

  dfs(root, 0);

  // cout << "Depths\n";
  // for (int i = 1; i <= n; i++)
  //  cout << "\t" << i << ": " << depths[i] << "\n";

  int a, b;
  cin >> a >> b;

  while (depths[a] != depths[b]) {
    if (depths[a] > depths[b])
      a = parents[a];
    else
      b = parents[b];
  }

  while (a != b) {
    a = parents[a];
    b = parents[b];
  }

  cout << a << "\n";
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
    solve();
}
