#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<int> edges[1000 + 1];
bool visited[1000 + 1];
bool processing[1000 + 1];
bool cycle;

void dfs(int u, stack<int>& st) {
  if (visited[u])
    return;

  visited[u] = true;
  processing[u] = true;
  for (int v : edges[u]) {
    if (processing[v]) // Found a backedge
      cycle = true;
    dfs(v, st);
  }
  st.push(u);
  processing[u] = false;
}

int main() {
  stack<int> st;
  cin >> n >> m;
  string line;

  while (m--) {
    int c;
    cin >> c;

    int from = -1, to;
    while (c--) {
      cin >> to;
      if (from != -1) {
        edges[from].push_back(to);
      }
      from = to;
    }
  }

  for (int i = 1; i <= n; i++)
    dfs(i, st);

  if (cycle)
    cout << "0\n";
  else {
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      cout << u << "\n";
    }
  }
}
