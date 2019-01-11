#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

#define MAX_NODE 10001
int parent[MAX_NODE];
vector<int> children[MAX_NODE];

int xaxis[MAX_NODE];

int minX[MAX_NODE];
int maxX[MAX_NODE];

int xvalue = 1;
int n;
int maxWidth = 0;
int depth = 0;

void findX(int n) {
  if (n == -1)
    return;

  findX(children[n][0]);
  xaxis[n] = xvalue++;
  findX(children[n][1]);
}

void findY(int n, int d) {
  if (n == -1)
    return;

  if (minX[d] > xaxis[n])
    minX[d] = xaxis[n];

  if (maxX[d] < xaxis[n])
    maxX[d] = xaxis[n];

  int width = maxX[d] - minX[d] + 1;
  if (width > maxWidth) {
    maxWidth = width;
    depth = d;
  }

  for (auto c : children[n]) {
    findY(c, d + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  memset(parent, -1, sizeof(parent));

  for (int i = 0; i < n; i++) {
    int a, l, r;
    cin >> a >> l >> r;
    if (l != -1) {
      parent[l] = a;
    }
    children[a].push_back(l);
    if (r != -1) {
      parent[r] = a;
    }
    children[a].push_back(r);
  }

  int root = -1;
  // find root
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      assert(root == -1);
      root = i;
    }
  }

//  cout << root << "\n";
//  return 0 ;

  for (int i = 1; i <= n; i++) {
    minX[i] = 1000000;
    maxX[i] = 0;
  }

  findX(root);
  findY(root, 1);

  cout << depth << " " << maxWidth << "\n";
}
