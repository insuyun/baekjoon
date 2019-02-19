#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct SegmentTree {
  vector<int> arr;

  void update(int node, int start, int end, int index, int value) {
    if (start > index || end < index)
      return;

    arr[node] = max(arr[node], value);

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index, value);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
    }
  }

  int query(int node, int start, int end, int left, int right) {
    if (left > end || start > right)
      return 0;

    if (left <= start && end <= right)
      return arr[node];

    return max(
        query(node * 2, start, (start + end) / 2, left, right),
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right)
    );
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    vector<pair<int, int>> inputs;
    int n = 0;
    SegmentTree t;
    scanf("%d", &n);
//    cin >> n;
    if (n == 0)
      break;
    t.arr.resize(1 << (1 + (int)ceil(log2(n))));

    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      inputs.push_back(make_pair(v, -i));
    }

    int m = 0;
    sort(inputs.begin(), inputs.end(), less<pair<int, int>>());

    for (auto c : inputs) {
      int value = c.first;
      int index = -c.second;
      int lis = t.query(1, 0, n - 1, 0, index) + 1;
      m = max(lis, m);
      t.update(1, 0, n - 1, index, lis);
    }

    cout << m << "\n";
  }
}
