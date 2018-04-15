#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
vector<int> edges[MAX];
int n;

int main() {
  int n;
  cin >> n;
  int s, e;
  cin >> s >> e;
  int m;
  cin >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  bool found = false;
  bool visited[MAX] = {};
  queue<int> q;
  q.push(s);
  visited[s] = true;
  int result = 0;

  while (!q.empty()) {
    int q_size = q.size();
    while (q_size--) {
      int u = q.front();
      q.pop();

      if (u == e) {
        found = true;
        break;
      }

      for (int v : edges[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    if (found)
      break;
    result ++;
  }

  cout << (found ? result : -1) << "\n";
}
