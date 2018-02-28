#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct {
  int num;
  int parent;
  int rank;
} node;

const int kMaxNum = 100000 + 1;

node nodes[kMaxNum];
unordered_map<string, int> user_map;

int f;
int gid;

int find_or_insert(string &n) {
  auto it = user_map.find(n);
  if (it == user_map.end())
    user_map.insert(make_pair(n, gid++));
  return user_map.find(n)->second;
}

int find_root(int v) {
  if (nodes[v].parent == -1)
    return v;

  return nodes[v].parent = find_root(nodes[v].parent);
}

int merge(int u, int v) {
  assert(nodes[u].parent == -1);
  assert(nodes[v].parent == -1);

  if (nodes[u].rank > nodes[v].rank)
    swap(u, v);
  else if (nodes[u].rank == nodes[v].rank)
    nodes[u].rank++;

  nodes[v].parent = u;
  nodes[u].num += nodes[v].num;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--) {
    std:: string n1, n2;
    cin >> f;
    gid = 0;
    user_map.clear();

    for (int i = 0; i < kMaxNum; i++) {
      nodes[i].num = 1;
      nodes[i].parent = -1;
      nodes[i].rank = 0;
    }

    for (int i = 0; i < f; i++) {
      cin >> n1 >> n2;
      int i1 = find_or_insert(n1);
      int i2 = find_or_insert(n2);


      int p1 = find_root(i1);
      int p2 = find_root(i2);
      int p;

      if (p1 != p2)
        p = merge(p1, p2);
      else
        p = p1;

      cout << nodes[p].num << "\n";
      // printf("p1: %d, p2: %d, p: %d, nodes[p].num: %d\n", p1, p2,
      //    p, nodes[p].num);

    }
  }
}
