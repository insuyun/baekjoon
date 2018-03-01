#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int kMaxNum = 10001;
int v, e;
vector<int> edges[kMaxNum];
vector<int> edges_r[kMaxNum];
bool visited[kMaxNum];
stack<int> st;

vector<int> cc[kMaxNum];
int ccmap[kMaxNum];
int ncc;

void dfs1(int x) {
  if (visited[x])
    return;

  visited[x] = true;
  for (int y : edges_r[x])
    dfs1(y);

  st.push(x);
}

bool dfs2(int x) {
  if (visited[x])
    return false;

  visited[x] = true;
  for (int y : edges[x])
    dfs2(y);

  ccmap[x] = ncc;
  cc[ncc].push_back(x);
  return true;
}

int main() {
  cin >> v >> e;

  for (int i = 0; i < e; i ++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges_r[b].push_back(a);
  }

  // 1. DFS on G^R to find order
  for (int i = 1; i <= v; i++)
    dfs1(i);

  memset(visited, 0, sizeof(visited));

  // 2. DFS on G
  while (!st.empty()) {
    int x = st.top();
    st.pop();
    if (dfs2(x))
      ncc++;
  }

  // Sort each cc
  for (int i = 0; i < ncc; i++)
    sort(cc[i].begin(), cc[i].end());

  memset(visited, 0, sizeof(visited));

  cout << ncc << "\n";
  for (int i = 1; i <= v; i++) {
    int cc_num = ccmap[i];
    if (visited[cc_num])
      continue;
    visited[cc_num] = true;

    for (int q : cc[cc_num])
      cout << q << " ";
    cout << "-1\n";
  }
}
