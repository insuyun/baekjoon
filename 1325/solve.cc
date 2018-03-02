#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

const int kMaxNum = 10001;

int n, m;
vector<int> edges[kMaxNum];
int hackable[kMaxNum];
bool visited[kMaxNum];
int num_visited = 0;

void dfs(int u) {
  if (visited[u])
    return;
  visited[u] = true;
  num_visited += 1;
  for (int v : edges[u])
    dfs(v);
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    num_visited = 0;
    memset(visited, 0, sizeof(visited));
    dfs(i);
    hackable[i] = num_visited;
  }

  // Find maximum
  int max_val = 0;
  for (int i = 1; i <= n; i++)
    max_val = max(hackable[i], max_val);

  // Print number who has maximum value
  for (int i = 1; i <= n; i++)
    if (max_val == hackable[i])
      cout << i << " ";
  cout << "\n";
}
