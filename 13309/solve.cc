#include <cassert>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int kMaxN = 200000 + 1;
const int kRoot = 1;
const int kUnassigned = -1;

int g_range_id = 1;

struct BinaryTree;

int N, Q;
int parents[kMaxN];
int weights[kMaxN];
vector<int> children[kMaxN];
int depths[kMaxN];
int heavy_path_indices[kMaxN];
vector<vector<int>> heavy_paths;
vector<BinaryTree*> trees;

void dfs(int v) {
    // cerr << "dfs: " << v << "\n";
    // FIXME: Iterative version
    if (v == kRoot)
        depths[v] = 0;
    else
        depths[v] = depths[parents[v]] + 1;

    for (int child : children[v]) {
        dfs(child);
    }

    weights[v]++;
    if (v != kRoot)
        weights[parents[v]] += weights[v];
}

void hld (int v) {
    if (v != kRoot) {
        // Heavy path
        if (weights[parents[v]] <= 2 * weights[v]
                && parents[v] != kRoot) {
            int heavy_path_index = heavy_path_indices[parents[v]];
            heavy_paths[heavy_path_index].push_back(v);
            heavy_path_indices[v] = heavy_path_index;
        }
        else {
            int heavy_path_index = heavy_paths.size();
            heavy_paths.resize(heavy_paths.size() + 1);
            heavy_paths[heavy_path_index].push_back(parents[v]);
            heavy_paths[heavy_path_index].push_back(v);
            heavy_path_indices[v] = heavy_path_index;
        }
    }

    for (int child : children[v]) {
        hld(child);
    }
}

struct BinaryTree {
    struct BinaryNode {
        int start;
        int end;
        int range_end;
        int range_id;
        BinaryNode *left, *right;

        // Range: [start, end]
        BinaryNode(int new_start, int new_end) :
            start(new_start), end(new_end),
            range_end(INT_MAX), range_id(kUnassigned),
            left(NULL), right(NULL) {
            assert(start <= end);

            if (new_start != new_end) {
                int mid = (start + end) / 2;
                left = new BinaryNode(start, mid);
                right = new BinaryNode(mid + 1, end);
            }
        }

        void update(int new_range_end, int new_range_id) {
            if (start > new_range_end)
                return;
            else if (end <= new_range_end) {
                if (range_end > new_range_end) {
                    range_id = new_range_id;
                    range_end = new_range_end;
                }
            }
            else {
                left->update(new_range_end, new_range_id);
                right->update(new_range_end, new_range_id);
            }
        }

        int query(int index) {
            int child_range_id = kUnassigned;
            if (start != end) {
                int mid = (start + end) / 2;
                if (index <= mid)
                    child_range_id = left->query(index);
                else
                    child_range_id = right->query(index);
            }

            // Not assigned yet
            if (child_range_id == kUnassigned)
                return range_id;
            else
                return child_range_id;
        }

        void print() {
          cerr
            << "\tPrint node:\n"
            << "\t\tstart: " << start << "\n"
            << "\t\tend: " << end << "\n"
            << "\t\trange_id: " << range_id << "\n"
            << "\t\trange_end: " << range_end << "\n";

            if (left != NULL) {
                left->print();
                right->print();
            }
        }
    };

    BinaryTree(int size_) : size(size_) {
        root = new BinaryNode(0, size_ - 1);
    }

    void update(int range_end, int range_id) {
        root->update(size - range_end - 1, range_id);
    }

    int query(int index) {
        return root->query(size - index - 1);
    }

    void print() {
        root->print();
    }

    int size;
    BinaryNode *root;
};

void print_heavy_path(int i) {
    cerr << "Printing " << i << "th heavy_path\n";

    vector<int>& heavy_path = heavy_paths[i];
    for (int j = 0; j < heavy_path.size(); j++) {
        cerr << "\t" << heavy_path[j] << " ";
    }
    cerr << "\n";
}

void print_tree(int index) {
  print_heavy_path(index);

  cerr << "Printing " << index << "th tree\n";
  trees[index]->print();
}

int get_range_id(int n) {
  int q = kUnassigned;

  while (q == kUnassigned && n != kRoot) {
    int heavy_path_index = heavy_path_indices[n];
    vector<int>& heavy_path = heavy_paths[heavy_path_index];
    int tree_index = depths[n] - depths[heavy_path[0]];
    q = trees[heavy_path_index]->query(tree_index);
    // print_tree(heavy_path_index);
    n = heavy_path[0];
  }

  // cerr << __func__ << ": " << q << "\n\n";
  return q;
}

bool check_connect(int b, int c) {
  // cerr << __func__ << ": " << b << ", " << c << "\n\n";
  return get_range_id(b) == get_range_id(c);
}

void cut_range(int n) {
  if (n == kRoot)
    return;

  int heavy_path_index = heavy_path_indices[n];
  vector<int>& heavy_path = heavy_paths[heavy_path_index];
  int tree_index = depths[n] - depths[heavy_path[0]];
  trees[heavy_path_index]->update(tree_index, g_range_id++);
  //print_tree(heavy_path_index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;

    for (int i = 2; i <= N; i++) {
        cin >> parents[i];
        children[parents[i]].push_back(i);
    }

    // Calculate depth and weight
    dfs(kRoot);

    hld(kRoot);

    // Create binary tree for each paths
    for (int i = 0; i < heavy_paths.size(); i++) {
        const vector<int>& heavy_path = heavy_paths[i];
        trees.push_back(new BinaryTree(heavy_path.size()));
    }

#if 0
    for (int i = 1; i <= N; i++) {
        cerr
            << i
            << "th node weight: " << weights[i]
            <<", depth: " << depths[i] << "\n";
    }

    for (int i = 0; i < heavy_paths.size(); i++) {
        vector<int>& heavy_path = heavy_paths[i];
        cerr << i << "th heavvy_path: ";
        for (int j = 0; j < heavy_path.size(); j++) {
            cerr << heavy_path[j] << " ";
        }
        cerr << "\n";
    }
#endif

    int b, c, d;
    for (int i = 1; i <= Q; i++)  {
        cin >> b >> c >> d;
        bool result = check_connect(b, c);
        if (result)
          printf("YES\n");
        else
          printf("NO\n");
        if (d == 1) {
          if (result) {
            cut_range(b);
          }
          else
          {
            cut_range(c);
          }
        }
    }

#if 0
    BinaryTree* tree = new BinaryTree(8);
    tree->print();

    cerr << "\n";
    tree->update(6, 1);
    tree->update(4, 2);
    tree->print();
    cerr << tree->query(4) << "\n";
    cerr << tree->query(5) << "\n";
#endif
}
