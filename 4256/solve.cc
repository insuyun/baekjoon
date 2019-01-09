#include <iostream>
#include <cassert>

using namespace std;

int n;
int preOrderIndex;
int preOrder[1001];
int inOrder[1001];

int root;
int leftChild[1001];
int rightChild[1001];

int findInOrderIndex(int start, int end, int value) {
  // cerr << "start: " << start << ", end: " << end << ", value: " << value << "\n";
  for (int i = start; i < end; i++) {
    if (inOrder[i] == value)
      return i;
  }
  assert(0);
  return 0;
}

void postOrder(int root) {
  if (root == -1)
    return;

  if (leftChild[root] != -1)
    postOrder(leftChild[root]);
  if (rightChild[root] != -1)
    postOrder(rightChild[root]);
  cout << root << " ";
}

int makeTree(int start, int end) {
  if (start >= end)
    return -1;
  int root = preOrder[preOrderIndex];
  preOrderIndex++;
  int index = findInOrderIndex(start, end, root);

  leftChild[root] = makeTree(start, index);
  rightChild[root] = makeTree(index + 1, end);

  //cerr << "curNode(" << root
  //  << ") - left: " << leftChild[curIndex]
  //  << ", right: " << rightChild[curIndex] << "\n";

  return root;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> preOrder[i];
    for (int i = 0; i < n; i++)
      cin >> inOrder[i];

    preOrderIndex = 0;
    root = preOrder[0];
    makeTree(0, n);
    postOrder(root);
    cout << "\n";
  }
}
