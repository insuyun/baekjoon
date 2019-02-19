#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct SegmentTree {
  vector<int64_t> arr;

  int64_t query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
      return 0;

    if (start == end)
      return arr[node];

    return query(node * 2, start, (start + end) / 2, left, right)
      + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  }

  void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end)
      return;

    arr[node] += diff;

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, diff);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
  }
};

int main() {
  int n, m;
  vector<int64_t> numbers;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  SegmentTree t;
  t.arr.resize(1 << (1 + (int)ceil(log2(n))));
  numbers.resize(n);

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
      if (b > c) {
        int tmp = b;
        b = c;
        c = tmp;
      }

      cout << t.query(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
    else if (a == 1) {
      int64_t diff = c - numbers[b - 1];
      t.update(1, 0, n - 1, b - 1, diff);
      numbers[b - 1] = c;
    }
  }
}
