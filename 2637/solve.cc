#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int kMax = 101;

int parts[kMax][kMax];
vector<int> edges[kMax];
vector<pair<int, int>> edges_r[kMax];
bool basic[kMax];
bool visited[kMax];

int n;

void dfs(int u, stack<int>& st) {
  if (visited[u])
    return;
  visited[u] = true;
  for (int v : edges[u])
    dfs(v, st);
  st.push(u);
}

int main() {
  int m;
  cin >> n >> m;

  while (m--) {
    int x, y, k;
    cin >> x >> y >> k;
    edges[y].push_back(x);
    edges_r[x].push_back(make_pair(y, k));
  }

  for (int i = 1; i <= n; i++) {
    if (edges[i].size() == 0)
      basic[i] = true;
  }

  // topological sort
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    dfs(i, st);
  }

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    if (edges_r[u].size() == 0) {
      // basic part
      // cout << "u: basic: " << u << "\n";
      parts[u][u] = 1;
    }
    else {
      for (pair<int, int>& p : edges_r[u]) {
        int v = p.first;
        int k = p.second;

        // cout << "add : " << u << "<-" << v << "\n";
        for (int i = 1; i <= n; i++)
          parts[u][i] += parts[v][i] * k;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (edges_r[i].size() == 0)
      cout << i << " " << parts[n][i] << "\n";
  }
}
