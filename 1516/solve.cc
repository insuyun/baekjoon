#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int kMax = 501;

int n;
int btime[kMax];
int tbtime[kMax];
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
  cin >> n;

  memset(btime, -1, sizeof(btime));
  memset(tbtime, -1, sizeof(tbtime));
  for (int i = 1; i <= n; i++) {
    while (true) {
      int a;
      cin >> a;
      if (a == -1)
        break;
      if (btime[i] == -1)
        btime[i] = a;
      else
        edges[a].push_back(i);
    }
  }

  stack<int> st;
  for (int i = 1; i <= n; i++)
    dfs(i, st);

  /*
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    cout << u << " ";
  }
  cout << "\n";
  */
  while (!st.empty()) {
    int i = st.top();
    st.pop();

    if (tbtime[i] == -1)
      tbtime[i] = btime[i];

    for (int v : edges[i])
      tbtime[v] = max(tbtime[v], tbtime[i] + btime[v]);
  }

  for (int i = 1; i <= n; i++)
    cout << tbtime[i] << "\n";
}
