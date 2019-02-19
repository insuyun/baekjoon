#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct SegmentTree {
  vector<int64_t> arr;

  int64_t init(vector<int64_t>& input, int node, int start, int end) {
    if (start == end) {
      arr[node] = input[start];
    }
    else {
      arr[node] = init(input, node * 2, start, (start + end) / 2)
        + init(input, node * 2 + 1, (start + end) / 2 + 1, end);
    }
    //cout << start << "-" << end << ": " << arr[node] << "\n";
    return arr[node];
  }

  void update(int node, int start, int end, int index, int64_t diff) {
    if (index < start || index > end)
      return;

    arr[node] += diff;

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, diff);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
  }

  int64_t query(int node, int start, int end, int left, int right) {
    // cout << "query: " << left << "-" << right << "\n";
    if (end < left || right < start)
      return 0;

    if (left <= start && end <= right)
      return arr[node];

    return query(node * 2, start, (start + end) / 2, left, right)
      + query(node * 2 + 1, (start + end ) / 2 + 1, end, left, right);
  }
};

int main() {
  int n, q;
  vector<int64_t> input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;

  SegmentTree t;
  for (int i = 0; i < n; i++) {
    int64_t v;
    cin >> v;
    input.push_back(v);
  }


  t.arr.resize(1 << ((int)ceil(log2(n)) + 1));
  t.init(input, 1, 0, n - 1);

  while (q--) {
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;

    if (x > y) {
      int tmp = x;
      x = y;
      y = tmp;
    }

    cout << t.query(1, 0, n - 1, x - 1, y - 1) << "\n";
    int64_t diff = b - input[a - 1];
    t.update(1, 0, n - 1, a - 1, diff);
    input[a - 1] = b;
  }
}
