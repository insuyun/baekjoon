#include <iostream>
#include <cstring>

using namespace std;

const int kMax = 101;
int n;
bool edges[kMax][kMax];
bool visited[kMax];

void dfs1(int node) {
  if (visited[node])
    return;

  visited[node] = true;
  for (int i = 0; i < n; i++) {
    if (edges[node][i])
      dfs1(i);
  }
}

void dfs(int node) {
  for (int i = 0; i < n; i++) {
    if (edges[node][i])
      dfs1(i);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int b;
      cin >> b;
      edges[i][j] = b;
    }
  }

  for (int i = 0; i < n; i++) {
    memset(visited, 0, n);
    dfs(i);
    for (int j = 0; j < n; j++) {
      if (visited[j])
        printf("1 ");
      else
        printf("0 ");
    }
    printf("\n");
  }
}
