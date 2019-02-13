#include <cmath>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

#define MAX_A 1000001

int n;
int tree[2097152 + 1];

struct SegTree {
  void init(int numNodes) {
    n = (1 << ((int)ceil(log2(numNodes)) + 1));
    assert(n < sizeof(tree) / 4);
  }

  void update(int index, int node, int start, int end, int diff) {
    if (index < start || index > end)
      return;

    tree[node] = max(tree[node], diff);
    // cout << start << "-" << end << ": " << diff << "\n";

    if (start != end) {
      update(index, node * 2, start, (start + end) / 2, diff);
      update(index, node * 2 + 1, (start + end) / 2 + 1, end, diff);
    }
  }

  int sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
      return 0;

    if (left <= start && end <= right) {
      // cout << start << "-" << end << ":" << left << "-" << right << "\n";
      return tree[node];
    }

    return max(sum(node * 2, start, (start + end) / 2, left, right),
        sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
  }

  void print(int node, int start, int end, int depth) {
    for (int i = 0; i < depth; i++)
      cout << " ";
    cout << start << " - " << end  << ": " << tree[node] << "\n";

    if (start != end) {
      print(node * 2, start, (start + end) / 2, depth +1);
      print(node * 2 + 1, (start + end) / 2 + 1, end, depth +1);
    }
  }
};

int main() {
  int n;
  cin >> n;
  SegTree tree;
  tree.init(MAX_A);

  int m = 0;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;

    int r = tree.sum(1, 0, MAX_A - 1, 0, c - 1);
    // cout << "r: " << r << "\n";
    m = max(r + 1, m);
    tree.update(c, 1, 0, MAX_A - 1, r + 1);
    // cout << "r - update: " << tree.sum(1, 0, MAX_A - 1, 0, c - 1) << "\n";
  }

  cout << m << "\n";
}
