#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

int next_node[MAX];
int visited[MAX];

int thenode;
int n;

bool dfs(int u) {
  visited[u] = -1;

  int v = next_node[u];
  bool res;

  if (visited[v] == -1) {
    res = true;
    thenode = v;
  }
  else if (visited[v] == 1)
    res = false;
  else
    res = dfs(v);

  visited[u] = 1;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      next_node[i] = a;
    }

    int remainder = n;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        if (dfs(i)) {
          int c = 1;
          int node = next_node[thenode];
          while (node != thenode) {
            node = next_node[node];
            c++;
          }

//          cout << "c: " << c << "\n";
          remainder -= c;
        }
        //cout << "DONE\n";
      }
    }

    cout << remainder << "\n";
  }
}
