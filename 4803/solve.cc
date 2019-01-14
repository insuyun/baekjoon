#include <iostream>
#include <vector>
#include <cstring>

#define MAX_NUM 501
using namespace std;

bool visited[MAX_NUM];
int parent[MAX_NUM];
int n, m;
vector<int> edges[MAX_NUM];

bool checkCycle(int n) {
  //cout << "checkCycle: " << n << "\n";
  bool hasCycle = false;
  visited[n] = true;
  for (auto c : edges[n]) {
    if (visited[c]) {
      if (parent[n] != c) { // cycle
        hasCycle = true;
      }
    }
    else {
      parent[c] = n;
      hasCycle |= checkCycle(c);
    }
  }

  return hasCycle;
}

int main() {
  int q = 0;
  while(true) {
    q++;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    // initialize
    for (int i = 0; i < MAX_NUM; i++)
      edges[i].clear();
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    int numTree = 0;

    while (m--) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        bool hasCycle = checkCycle(i);
        //cout << i << ": " << hasCycle << "\n";
        if (!hasCycle)
          numTree++;
      }
    }

    if (numTree > 1)
      cout << "Case " << q << ": A forest of " << numTree << " trees.\n";
    else if (numTree == 1)
      cout << "Case " << q << ": There is one tree.\n";
    else
      cout << "Case " << q << ": No trees.\n";
  }

}
