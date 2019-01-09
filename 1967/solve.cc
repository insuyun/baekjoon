#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

int n;
int parents[MAX];
int weights[MAX];
int weightedDepth[MAX];
vector<int> children[MAX];

int maxDistance = 0;

int findWeightedDepth(int root) {
  int maxDepth = 0, secondMaxDepth = 0;
  for (auto child : children[root]) {
    int newDepth = findWeightedDepth(child) + weights[child];
    if (newDepth > maxDepth) {
      secondMaxDepth = maxDepth;
      maxDepth = newDepth;
      maxDistance = max(maxDistance, maxDepth + secondMaxDepth);
    }
    else if (newDepth > secondMaxDepth) {
      secondMaxDepth = newDepth;
      maxDistance = max(maxDistance, maxDepth + secondMaxDepth);
    }
  }
  weightedDepth[root] = maxDepth;
  // cout << root << ":" << weightedDepth[root] << "\n";
  return maxDepth;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    weights[child] = weight;
    parents[child] = parent;
    children[parent].push_back(child);
  }

  findWeightedDepth(1);
  cout << maxDistance << "\n";
}
