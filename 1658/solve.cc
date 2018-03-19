#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_map>

using namespace std;

const int kMaxPigHouse = 1001;
const int kStageStep = kMaxPigHouse + 3;
const int kMaxNodes = kStageStep * 101 + 1;
const int kStart = 0;
const int kEnd = kMaxNodes - 1;
const int INF = 10000000;

int n, m;

int keys[kMaxPigHouse];
vector<int> edges[kMaxNodes];
int stage_offset = 0;
unordered_map<int, int> c[kMaxNodes];
unordered_map<int, int> f[kMaxNodes];

int encode(int x) {
  return x + stage_offset;
}

int next(int x) {
  return x + stage_offset + kStageStep;
}

int get_stage_end() {
  return encode(kStageStep - 1);
}

int get_stage_mid(int off) {
  return encode(kStageStep - off - 2);
}

string repr(int x) {
  return to_string(x / kStageStep) + ", " + to_string(x % kStageStep);
}

void add_edge(int x, int y, int w) {
  edges[x].push_back(y);
  edges[y].push_back(x);
  assert(c[x][y] == 0);
  c[x][y] = w;
  c[y][x] = 0;
  f[x][y] = 0;
  f[y][x] = 0;
//   cout << "x(" << repr(x) << ") -> y(" << repr(y) << "): " << w << "\n";
}

void dfs(int u, unordered_map<int, bool> &visited, unordered_map<int, int>& parent) {
  for (int v : edges[u]) {
    if (!visited[v] && c[u][v] - f[u][v] > 0) {
      visited[v] = true;
      parent[v] = u;
      dfs(v, visited, parent);
    }
  }
}

int main() {
  cin >> m >> n;

  for (int i = 1; i <= m; i++) {
    int v;
    cin >> v;
    add_edge(kStart, i, v);
  }

  while (n--) {
    int a, b;
    cin >> a;
    for (int i = 1; i <= a; i++)
      cin >> keys[i];
    cin >> b;

    // 1. go to destination
    for (int i = 1; i <= a; i++)
      add_edge(encode(keys[i]), get_stage_end(), INF);
    add_edge(get_stage_end(), kEnd, b);

    // 2. shuffle
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= a; j++) {
        if (i == j)
          continue;
        add_edge(encode(keys[i]), next(keys[j]), INF);
      }
    }

    // 3. go to next node
    for (int i = 1; i <= m; i++)
      add_edge(encode(i), next(i), INF);

    stage_offset += kStageStep;
  }

  int max_flow = 0;
  // Run Maxflow algorithm
  while (true) {
    // Find an augment path
    bool visited[kMaxNodes] = {};
    int parent[kMaxNodes] = {};
    visited[kStart] = true;

//    dfs(kStart, visited, parent);
    queue<int> q;
    q.push(kStart);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : edges[u]) {
        if (!visited[v] && c[u][v] - f[u][v] > 0) {
          visited[v] = true;
          q.push(v);
          parent[v] = u;
        }
      }
    }
    if (!visited[kEnd])
      break;

    int flow = INF;
    int u = kEnd;
    while (u != kStart) {
//       cout << u << "\n";
      flow = min(flow, c[parent[u]][u] - f[parent[u]][u]);
      u = parent[u];
    }

    u = kEnd;
    while (u != kStart) {
      f[parent[u]][u] += flow;
      f[u][parent[u]] -= flow;
      u = parent[u];
    }

//    cout << "FLOW: " << flow << "\n";
    max_flow += flow;
  }

  cout << max_flow << "\n";
}
