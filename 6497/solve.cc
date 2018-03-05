#include <vector>
#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

const int kMaxNum = 200000 + 1;

vector<pair<int, int>> edges[kMaxNum];
bool visited[kMaxNum];

int main() {
  while (true) {
    int m, n;
    cin >> m >> n;

    if (m == n && n == 0)
      return 1;
    priority_queue<pair<int, int>> pq;

    int total = 0;
    while (n--) {
      int x, y, z;
      cin >> x >> y >> z;
      edges[x].push_back(make_pair(-z, y));
      edges[y].push_back(make_pair(-z, x));
      total += z;
    }

    pq.push(make_pair(0, 0));

    int mst = 0;

    while (!pq.empty()) {
      pair<int, int> p = pq.top();
      pq.pop();

      if (visited[p.second])
        continue;

      visited[p.second] = true;
      mst -= p.first;

      //    printf("-> %d: %d\n", p.second, p.first);

      for (pair<int, int> e : edges[p.second])
        pq.push(e);
    }

    printf("%d\n", total - mst);

    for (int i = 0; i < m; i++) {
      visited[i] = false;
      edges[i].clear();
    }
  }
}
