#include <iostream>
#include <assert.h>
#include <queue>
#include <cstring>

using namespace std;

bool visited[1001];
bool finished[1001];
int edge[1001];
int components[1001];
int depths[1001];
int n, k;
int cycle_num = 0;
int depth = 0;
int cycle_size[1001];
int components_size[1001];
bool arr[1001][1001]; // use until ith cycloe, make j people

int dfs(int x) {
  assert(!visited[x]);
  depth++;

  int next = edge[x];
  int r = -1;

  depths[x] = depth;
  visited[x] = true;

  if (visited[next]) {
    if (!finished[next]) {
      // found cycle
      r = cycle_num++;
      cycle_size[r] = depth - depths[next] + 1;
    }
  }
  else {
    r = dfs(next);
  }

  finished[x] = true;
  components[x] = r;
  depth--;
  return r;
}

int dfs2(int x, int r) {
  assert(!visited[x]);
  visited[x] = true;

  if (components[x] != -1)
    r = components[x];
  int next = edge[x];

  if (!visited[next])
    r = dfs2(next, r);
  else {
    if (components[next] != -1)
      r = components[next];
  }

  components[x] = r;
  return r;
}

int main() {
  cin >> n >> k;

  memset(components, -1, sizeof(components));

  for (int i = 1; i <= n; i++)
    cin >> edge[i];

  for (int i = 1; i <= n; i++) {
    // already handled
    if (visited[i])
      continue;

    dfs(i);
  }

  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    dfs2(i, -1);
  }

//  for (int i = 1; i <= n; i++) {
//    cout << "component: " << components[i];
//    if (components[i] != -1)
//      cout << ", " << cycle_size[components[i]];
//    cout << "\n";
//    if (visited[i])
//      continue;
//  }

  // count component size
  for (int i = 1; i <= n; i++) {
    components_size[components[i]]++;
  }

//  for (int i = 0; i < cycle_num; i++) {
//    cout << i << ", " << components_size[i] << ", " << cycle_size[i] << "\n";
//  }
//

  arr[0][0] = true;

  // cout << "gogo\n";
  for (int i = 0; i < cycle_num; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (arr[i][j] == true) {
        arr[i + 1][j] = true;
        for (int q = 0; q <= components_size[i] - cycle_size[i]; q++) {
          int new_y = j + cycle_size[i] + q;
          if (new_y < k + 1) {
            arr[i+1][new_y] = true;
//            cout << i << ", " << new_y << "\n";
          }
        }
      }
    }
  }

  int r = -2;
  for (int i = k; i >= 0; i--) {
    if (arr[cycle_num][i] == true) {
      r = i;
      break;
    }
  }

  cout << r << "\n";
}
