#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>

using namespace std;

int v, e;
const int kMaxVerticies = 10000 + 1;

vector<pair<int, int>> edges[kMaxVerticies];
bool visited[kMaxVerticies];

int main() {
  cin >> v >> e;
  priority_queue<pair<int, int>> pq;

  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a].push_back(make_pair(-w, b));
    edges[b].push_back(make_pair(-w, a));
  }

  int64_t cost = 0;
  for (pair<int, int>& e : edges[1])
    pq.push(e);

  visited[1] = true;

  while (!pq.empty()) {
    pair<int, int> e = pq.top();
    pq.pop();

    if (visited[e.second])
      continue;

    visited[e.second] = true;
    cost += -e.first;

    for (pair<int, int>& ne : edges[e.second])
      pq.push(ne);
  }

  cout << cost << "\n";
}
