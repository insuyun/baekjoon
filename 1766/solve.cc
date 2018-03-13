#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
const int kMax = 32000 + 1;
vector<int> edges[kMax];
int n_incoming[kMax];

int main() {
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    n_incoming[b]++;
  }

  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    if (n_incoming[i] == 0)
      pq.push(-i);
  }

  while (!pq.empty()) {
    int u = -pq.top();
    pq.pop();
    cout << u << " ";

    for (int v : edges[u]) {
      n_incoming[v]--;
      if (n_incoming[v] == 0)
        pq.push(-v);
    }
  }

  cout << "\n";
}
