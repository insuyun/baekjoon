#include <iostream>

#define MAX_N 100001
#define MAX_V 1000000000

using namespace std;

struct SegmentTree {
  int arr[262144];

  void update(int node, int start, int end, int index, int value) {
    if (index < start || index > end)
      return;

    arr[node] = max(arr[node], value);

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, value);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
    }
  }

  int query(int node, int start, int end, int left, int right) {
    // cout << node << ", " << start << ", " << end << ", " << left << ", " << right << "\n";
    if (left > end || right < start)
      return -MAX_V;

    if (left <= start && end <= right)
      return arr[node];

    if (start != end) {
      return max(
          query(node * 2, start, (start + end) / 2, left, right),
          query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }
    else
      return -MAX_V;
  }
};

int main() {
  int n, m;
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  SegmentTree t1, t2;

  for (int i = 0; i < 262144; i++)
    t2.arr[i] = -MAX_V;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    t1.update(1, 0, n - 1, i, v);
    t2.update(1, 0, n - 1, i, -v);
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << -t2.query(1, 0, n - 1, a - 1, b - 1) << " "
      << t1.query(1, 0, n - 1, a - 1, b - 1) << "\n";
  }
}
