#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int kMax = 32000 + 1;
vector<int> edges[kMax];
bool visited[kMax];

int n, m;

void dfs(int u, stack<int>& st) {
  if (visited[u])
    return;

  visited[u] = true;
  for (int v : edges[u])
    dfs(v, st);

  st.push(u);
}

int main() {
  stack<int> st;
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  for (int i = 1; i <= n; i++)
    dfs(i, st);

  while (!st.empty()) {
    cout << st.top() << "\n";
    st.pop();
  }
}
