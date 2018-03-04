#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int kMaxNum = 101 * 2 + 1;

int n, m;

vector<int> edges[kMaxNum];
vector<int> edges_r[kMaxNum];
bool visited[kMaxNum];
int cc_map[kMaxNum];
vector<int> cc_nodes[kMaxNum];

int encode(int node) {
  // map -1 --> 101
  if (node <= 0)
    node = 100 - node;
  return node;
}

void add_edge(int from, int to) {
  edges[encode(from)].push_back(encode(to));
  edges_r[encode(to)].push_back(encode(from));
}

bool sat() {
  for (int i = 1; i <= n; i++) {
    if (cc_map[i] == cc_map[encode(-i)])
      return false;
  }
  return true;
}

void kosaraju1(int node, stack<int>& st) {
  if (visited[node])
    return;
  visited[node] = true;

  for (int next : edges_r[node])
    kosaraju1(next, st);

  st.push(node);
}

void kosaraju2(int node, int cc_id) {
  if (visited[node])
    return;
  visited[node] = true;

  for (int next : edges[node])
    kosaraju2(next, cc_id);

  cc_map[node] = cc_id;
  cc_nodes[cc_id].push_back(node);
}

int main() {
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    // x \disjunction y --> (\not x -> y) | (\not y -> x)
    add_edge(-a, b);
    add_edge(-b, a);
  }

  // Run algorithm for SCC
  stack<int> st;
  for (int i = -n; i <= n; i++)
    kosaraju1(encode(i), st);

  memset(visited, 0, sizeof(visited));
  int cc_id = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      kosaraju2(node, cc_id);
      cc_id++;
    }
  }

  // Check if x & -x in the same node
  if (sat())
    cout << "1\n";
  else
    cout << "0\n";
}
