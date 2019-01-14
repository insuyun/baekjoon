#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n;
vector<int> edges[100001];
int parent[100001];

void makeTree(int n) {
//  cout << n << "\n";
  for (auto c : edges[n]) {
    if (parent[c] != -1)
      continue;
    parent[c] = n;
    makeTree(c);
  }
}

int main() {
  memset(parent, -1, sizeof(parent));
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  parent[1] = 0;
  makeTree(1);

  for (int i = 2; i <= n; i++)
    cout << parent[i] << "\n";
}
