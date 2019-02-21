#include <iostream>
#include <cmath>
#include <vector>

#define PRIME 1000000007

using namespace std;

struct SegmentTree {
  vector<int64_t> arr;

  int64_t init(vector<int64_t> inputs, int node, int start, int end) {
    if (start == end)
      return arr[node] = inputs[start];
    else {
      return arr[node] = (init(inputs, node * 2, start, (start + end) / 2)
          * init(inputs, node * 2 + 1, (start + end) / 2 + 1, end)) % PRIME;
    }
  }

  int64_t update(int node, int start, int end, int index, int64_t val) {
    if (index < start || index > end)
      return arr[node];

    if (start == end)
      return arr[node] = val;
    else {
      return arr[node] = (update(node * 2, start, (start + end) / 2, index, val)
        * update(node * 2 + 1, (start + end) / 2 + 1, end, index, val) ) % PRIME;
    }
  }

  int64_t query(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
      return 1;

    if (left <= start && end <= right)
      return arr[node];

    return (query(node * 2, start, (start + end) / 2, left, right)
      * query(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % PRIME;
  }
};

int main() {
  int n, m, k;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  SegmentTree t;
  vector<int64_t> inputs;
  inputs.reserve(n);

  for (int i = 0; i < n; i++) {
    int64_t v;
    cin >> v;
    inputs.push_back(v % PRIME);
  }

  t.arr.resize(1 << (1 + (int)ceil(log2(n))));
  t.init(inputs, 1, 0, n - 1);

  for (int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      t.update(1, 0, n - 1, b - 1, c);
    }
    else if (a == 2) {
      cout << t.query(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
  }
}
