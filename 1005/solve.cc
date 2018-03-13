#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int kMax = 1001;
int n, k;
int btime[kMax];
int ttime[kMax];
vector<int> edges[kMax];
bool visited[kMax];

void dfs(int u, stack<int>& st) {
  if (visited[u])
    return;

  visited[u] = true;
  for (int v : edges[u])
    dfs(v, st);
  st.push(u);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(ttime, -1, sizeof(ttime));
    memset(visited, 0, sizeof(visited));

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
      cin >> btime[i];

    while (k--) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
    }

    stack<int> st;
    for (int i = 1; i <= n; i++)
      dfs(i, st);

    while (!st.empty()) {
      int u = st.top();
      st.pop();

      if (ttime[u] == -1)
        ttime[u] = btime[u];

      for (int v : edges[u]) {
        ttime[v] = max(ttime[v], ttime[u] + btime[v]);
      }
    }

    // Clean up
    for (int i = 1; i <= n; i++)
      edges[i].clear();

    int w;
    cin >> w;
    cout << ttime[w] << "\n";
  }
}
