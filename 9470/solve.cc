#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int kMax = 1001;
vector<int> edges[kMax];
vector<int> edges_r[kMax];
int strahler[kMax];
bool visited[kMax];

void dfs(int u, stack<int> &st) {
  if (visited[u])
    return;
  visited[u] = true;

  for (int v : edges[u])
    dfs(v, st);
  st.push(u);
}

int main() {
  int k;
  cin >> k;

  while (k--) {
    int k, m, p;
    cin >> k >> m >> p;

    memset(visited, 0, sizeof(visited));

    while (p--) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges_r[b].push_back(a);
    }

    // topological sorting
    stack<int> st;
    for (int i = 1; i <= m; i++)
      dfs(i, st);

    while (!st.empty()) {
      int u = st.top();
      st.pop();
      if (edges_r[u].size() == 0) {
        // No edge
        strahler[u] = 1;
      }
      else {
        int ms = 0;
        for (int v : edges_r[u])
          ms = max(strahler[v], ms);
        int c = 0;
        for (int v : edges_r[u])
          if (strahler[v] == ms)
            c++;

        if (c >= 2)
          strahler[u] = ms + 1;
        else
          strahler[u] = ms;
      }
    }

    cout << k << " " << strahler[m] <<"\n";

    for (int i = 1; i <= m; i++) {
//      cout << i << ": " << strahler[i] << "\n";
      edges[i].clear();
      edges_r[i].clear();
    }
  }
}
