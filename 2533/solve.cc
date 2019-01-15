#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;
#define MAX_NODES 1000001

int n;
vector<int> edges[MAX_NODES];
int parent[MAX_NODES];
vector<int> children[MAX_NODES];
int cache[MAX_NODES][2];

void makeTree(int n) {
  for (auto c : edges[n]) {
    if (parent[c] == 0) {
      parent[c] = n;
      children[n].push_back(c);
      makeTree(c);
    }
  }
}

int findEarlyAdaoptor(int n, bool choose) {
  int &r = cache[n][choose];
//   cout << "findEarlyAdaoptor: " << n << ", " << choose << "\n";
  if (r != -1)
    return r;

  if (choose) {
    r = 1;
    for (auto c : children[n]) {
      r += min(findEarlyAdaoptor(c, false), findEarlyAdaoptor(c, true));
    }
//     cout << "res(" << n << ", " << choose << "): " << r << "\n";
    return r ;
  }
  else {
    r = 0;
    for (auto c : children[n]) {
      r += findEarlyAdaoptor(c, true);
    }
    // cout << "res(" << n << ", " << choose << "): " << r << "\n";
    return r;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  memset(cache, -1, sizeof(cache));

  parent[1] = -1;
  makeTree(1);

  cout << min(findEarlyAdaoptor(1, false), findEarlyAdaoptor(1, true)) << "\n";
}
