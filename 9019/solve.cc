#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10000;

int fl(int n) {
  int d[4];

  for (int i = 0; i < 4; i++) {
    d[i] = n % 10;
    n /= 10;
  }
  return d[2] * 1000 + d[1] * 100 + d[0] * 10 + d[3];
}

int fr(int n) {
  int d[4];

  for (int i = 0; i < 4; i++) {
    d[i] = n % 10;
    n /= 10;
  }
  return d[0] * 1000 + d[3] * 100 + d[2] * 10 + d[1];
}


int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    char prev[10000] = {};
    int parent[10000] = {};
    bool visited[10000] = {};
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

//      printf("%d\n", u);
      if (u == b)
        break;

      const char op[4] = {'D', 'S', 'L', 'R'};
      int values[4] = {
        (u * 2) % MAX,
        (u == 0 ? MAX - 1 : u - 1),
        fl(u),
        fr(u) };

      for (int i = 0; i < 4; i++) {
        if (!visited[values[i]]) {
          visited[values[i]] = true;
          q.push(values[i]);
          prev[values[i]] = op[i];
          parent[values[i]] = u;
        }
      }
    }

    vector<char> v;
    int tmp = b;
    while (tmp != a) {
      v.push_back(prev[tmp]);
      tmp = parent[tmp];
    }

    reverse(v.begin(), v.end());
    cout << string(v.begin(), v.end()) << "\n";
  }
}
