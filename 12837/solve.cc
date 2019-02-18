#include <iostream>
#include <cmath>

#define MAX_N 1000001

using namespace std;

struct SegmentTree {
  int64_t *arr;

  void init(int n) {
    arr = (int64_t*)calloc(sizeof(int64_t), n);
  }

  void update(int node, int start, int end, int index, int64_t value) {
    if (index < start || index > end)
      return;

    arr[node] += value;

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, value);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
    }
  }

  int64_t query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
      return 0;

    if (left <= start && end <= right)
      return arr[node];

    if (start != end) {
      return query(node * 2, start, (start + end) / 2, left, right)
        + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  SegmentTree t;

  int n, m;
  cin >> n >> m;

  t.init(1 << (1 + (int)ceil(log2(n))));

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      t.update(1, 0, n - 1, b - 1, c);
    }
    else
      cout << t.query(1, 0, n - 1, b - 1, c - 1) << "\n";
  }
}
