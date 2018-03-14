#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

const int kMax = 501;
bool edges[kMax][kMax];

// Edge from higher rank (smaller) to lower rank
// y < x --> y -> x
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int lastyear[n];

    memset(edges, 0, sizeof(edges));

    for (int i = 1; i <= n; i++)
      cin >> lastyear[i];

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        edges[lastyear[i]][lastyear[j]] = true;
      }
    }

#if 0
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cout << i << "(" << lastyear[i] << "), " << j
          << "(" << lastyear[j] << "): "
          << edges[i][j] << "\n";
#endif
    int m;
    cin >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;

      if (edges[a][b]) {
        edges[a][b] = false;
        edges[b][a] = true;
      }
      else {
        assert(edges[b][a]);
        edges[a][b] = true;
        edges[b][a] = false;
      }
    }

    // topological sort
    queue<int> q;
    int indegree[kMax] = {};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (edges[j][i])
          indegree[i]++;
      }
    }

    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    int n_visit = 0;
    bool ambiguous = false;
    vector<int> order;

    while (!q.empty()) {
      if (q.size() >= 2) {
        ambiguous = true;
        break;
      }

      int u = q.front();
      order.push_back(u);
      q.pop();

      for (int i = 1; i <= n; i++) {
        if (edges[u][i]) {
          indegree[i]--;
          if (indegree[i] == 0)
            q.push(i);
        }
      }
    }

    if (ambiguous) {
      assert(false);
      cout << "?\n";
    }
    else if (order.size() != n)
      cout << "IMPOSSIBLE\n";
    else {
      for (int i = 0; i < n; i++)
        cout << order[i] << " ";
      cout << "\n";
    }
  }
}
