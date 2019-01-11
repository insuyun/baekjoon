#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int weights[10001];

vector<int> edges[10001];
vector<int> children[10001];
int parent[10001];
bool visited[10001];
int cache[10001];

void dfs(int n) {
  visited[n] = true;
  for (auto c: edges[n]) {
    if (!visited[c]) {
      parent[c] = n;
      children[n].push_back(c);
      dfs(c);
    }
  }
}

int calcMax(int n) {
  // maximum value if r is root

  int &r = cache[n];
  if (r != -1)
    return r;

  // 1. mark this node
  r = weights[n];
  for (auto c : children[n]) {
    for (auto cc : children[c]) {
      r += calcMax(cc);
    }
  }

  int sum = 0;
  // 2. don't mark this node
  for (auto c : children[n]) {
    sum += calcMax(c);
  }

  r = max(sum, r);

  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> weights[i];

  for (int i = 1; i <= n-1; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
    // cout << x << " -> " << y << "\n";
  }

  dfs(1);

  cout << calcMax(1) << "\n";
}
