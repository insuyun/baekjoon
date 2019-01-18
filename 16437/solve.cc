#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

#define MAX_NODES 123457

int64_t n;

char kind[MAX_NODES];
int64_t weights[MAX_NODES];
vector<int64_t> edges[MAX_NODES];
vector<int64_t> children[MAX_NODES];
int64_t parent[MAX_NODES];
bool visited[MAX_NODES];

int64_t makeTree(int64_t r) {
  for (auto c : edges[r]) {
    if (!visited[c]) {
      parent[c] = r;
      children[r].push_back(c);
      visited[c] = true;
      makeTree(c);
    }
  }
}

int64_t findSheep(int64_t r) {
  int64_t sheep = 0;
  for (auto c : children[r]) {
    sheep += findSheep(c);
  }

  int64_t res = 0;
  if (kind[r] == 'W')
    res = max(0L, sheep - weights[r]);
  else
    res = sheep + weights[r];

  // cout << r << ": " << res << "\n";
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int64_t i = 2; i <= n; i++) {
    int64_t to;
    cin >> kind[i] >> weights[i] >> to;
    edges[i].push_back(to);
    edges[to].push_back(i);
  }

  visited[1] = true;
  makeTree(1);

  cout << findSheep(1) << "\n";
}
