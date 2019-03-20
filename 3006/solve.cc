#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

struct SegmentTree {
  int* arr;

  SegmentTree(int n) {
    arr = new int [(1 << ((int)ceil(log2(n)) + 1)) + 1];
  }

  void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end)
      return;

    if (start <= index && index <= end)
      arr[node] += diff;

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, diff);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
  }

  int query(int node, int start, int end, int left, int right) {
    if (left <= start && end <= right)
      return arr[node];

    if (start > right || left > end)
      return 0;

    return query(node * 2, start, (start + end) / 2, left, right)
      + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> numbers;
  vector<int> reverseMap;
  int n;
  cin >> n;

  SegmentTree t(n);
  reverseMap.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    numbers.push_back(a);
    reverseMap[a] = i;
  }

  for (int i = 0; i < n; i++) {
    int index, step;
    if (i % 2 == 0) {
      index = reverseMap[i / 2 + 1];
      step = index - t.query(1, 0, n - 1, 0, index);
      t.update(1, 0, n - 1, index, 1);
    }
    else {
      index = reverseMap[n - i / 2];
      step = (n - 1) - index - t.query(1, 0, n - 1, index, n - 1);
      t.update(1, 0, n - 1, index, 1);
    }

    cout << step << "\n";
  }
}
