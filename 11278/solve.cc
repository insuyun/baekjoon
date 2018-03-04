#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int kMaxNum = 101 * 2 + 1;
const int kOffset = 100;

int n, m;

vector<int> edges[kMaxNum];
vector<int> edges_r[kMaxNum];
bool visited[kMaxNum];
int cc_id = 0;
int cc_map[kMaxNum];
vector<int> cc_nodes[kMaxNum];
int solution[kMaxNum];

int encode(int node) {
  // map -1 --> 101
  if (node <= 0)
    node = kOffset - node;
  return node;
}

int decode(int node) {
  if (node > kOffset)
    node = -node + kOffset;
  return node;
}

void add_edge(int from, int to) {
  // printf("add_edge: %d->%d\n", from, to);
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

void kosaraju2(int node) {
  if (visited[node])
    return;
  visited[node] = true;

  for (int next : edges[node])
    kosaraju2(next);

  cc_map[node] = cc_id;
  cc_nodes[cc_id].push_back(node);
}

void print_solution() {
  for (int i = 0; i < cc_id; i++) {
    // hasn't decide yet
    for (int node : cc_nodes[i]) {
      int decoded = decode(node);
      if (decoded < 0)
        solution[-decoded] = solution[-decoded] == 0 ? -1 : solution[-decoded];
      else
        solution[decoded] = solution[decoded] == 0 ? 1 : solution[decoded];
    }
  }

  for (int i = 1; i <= n; i++) {
    // printf("solution: %d\n", solution[i]);
    if (solution[i] == 1)
      printf("1 ");
    else
      printf("0 ");
  }
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
  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      kosaraju2(node);
      cc_id++;
    }
  }
#if 0
  printf("cc-map: ");
  for (int i = -n; i <= n; i++) {
    int node = encode(i);
    printf("(%d: %d) ", i, cc_map[node]);
  }
  printf("\n");
#endif

  // Check if x & -x in the same node
  if (sat()) {
    cout << "1\n";
    print_solution();
  }
  else
    cout << "0\n";
}
