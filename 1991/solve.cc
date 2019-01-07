#include <iostream>

using namespace std;

struct TreeNode {
  public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    char id;

    TreeNode(char id):
      id(id), left(NULL), right(NULL), parent(NULL) { }
};

TreeNode* nodes['Z' - 'A' + 1];
int n;

TreeNode* getOrCreate(char id) {
  if (nodes[id - 'A'])
    return nodes[id - 'A'];
  else {
    TreeNode* node = new TreeNode(id);
    nodes[id - 'A'] = node;
    return node;
  }
}

void preOrder(TreeNode* node) {
  if (node == NULL)
    return;

  cout << node->id;
  preOrder(node->left);
  preOrder(node->right);
}

void inOrder(TreeNode* node) {
  if (node == NULL)
    return;

  inOrder(node->left);
  cout << node->id;
  inOrder(node->right);
}

void postOrder(TreeNode* node) {
  if (node == NULL)
    return;

  postOrder(node->left);
  postOrder(node->right);
  cout << node->id;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    char left, cur, right;
    cin >> cur >> left >> right;
    TreeNode *node = getOrCreate(cur);

    if (left != '.')
      node->left = getOrCreate(left);

    if (right != '.')
      node->right = getOrCreate(right);
  }

  preOrder(nodes[0]);
  cout << "\n";

  inOrder(nodes[0]);
  cout << "\n";

  postOrder(nodes[0]);
  cout << "\n";
}
