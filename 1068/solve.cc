#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_NODES 51

int parent[MAX_NODES];
vector<int> children[MAX_NODES];

int countLeaf(int n) {
  if (children[n].empty()) {
    return 1;
  }

  int r = 0;
  for (auto c : children[n]) {
    r += countLeaf(c);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int root;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> parent[i];
    if (parent[i] == -1) {
      root = i;
    }
    else
      children[parent[i]].push_back(i);
  }

  int x;
  cin >> x;

  if (x == root) {
    cout << "0\n";
    exit(0);
  }

  // XXX: Don't need this line
  children[x].clear();
  vector<int>& vec = children[parent[x]];
  vec.erase(std::remove(vec.begin(), vec.end(), x), vec.end());

  cout << countLeaf(root) << "\n";
}
