#include <iostream>
#include <cassert>

using namespace std;

int n, m, k;

struct SegmentNode;

int64_t num[1000000];

typedef struct SegmentTree {
  typedef struct SegmentNode {

    SegmentNode(int beg, int end)
    : beg(beg), end(end), left(NULL), right(NULL) {
      assert(end >= beg);
      if (beg != end) {
        int mid = (beg + end) / 2;
        left = new SegmentNode(beg, mid);
        right = new SegmentNode(mid + 1, end);
        value = left->value + right->value;
      }
      else
        value = num[beg];

      //cout << "beg: " << beg << ", end: " << end << ", value: " << value << "\n";
    }

    void update(int pos, int64_t diff) {
      if (pos < beg || end <  pos)
        return;

      value += diff;
      if (pos == beg && beg == end)
        return;

      assert(beg != end);
      left->update(pos, diff);
      right->update(pos, diff);
    }

    int64_t query(int beg_, int end_) {
      // cout << "q: " << beg_ << ", " << end_ << "\n";
      // []
      if (end < beg_ || beg > end_)
        return 0;

      if (beg_ == beg && end_ == end)
        return value;

      int mid = (beg + end) / 2;
      assert(beg != end);
      return left->query(beg_, min(end_, mid))
        + right->query(max(mid + 1, beg_), end_);
    }

    SegmentNode* left;
    SegmentNode* right;

    int64_t value;
    int beg;
    int end;
  } SegmentNode;


  SegmentTree(int n) {
    root = new SegmentNode(0, n - 1);
  }

  void update(int pos, int64_t value) {
    int64_t diff = value - num[pos];
    num[pos] = value;
    root->update(pos, diff);
  }

  int64_t query(int beg, int end) {
    return root->query(beg, end);
  }

  SegmentNode* root;

} SegmentTree;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
    cin >> num[i];

  SegmentTree *t = new SegmentTree(n);
  // cout << t->root->value << "\n";

  for (int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
      t->update(b - 1, c);
    else
      cout << t->query(b - 1, c - 1) << "\n";
  }
}
