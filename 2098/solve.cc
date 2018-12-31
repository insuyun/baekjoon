#include <iostream>
#include <climits>

using namespace std;

#define MAX 1000000000

int n;
int weight[18][18];
int cache[16][1<<16];

int dfs(int lastVisit, int visited) {
  int &ret = cache[lastVisit][visited];
  if (ret != 0)
    return ret;

  if (visited == ((1 << n) - 1)) {
    if (weight[lastVisit][0])
      return weight[lastVisit][0];
    else
      return MAX;
  }

  ret = MAX;
  for (int i = 0; i < n; i++) {
    if (weight[lastVisit][i] && !(visited & (1 << i))) {
        ret = min(ret, dfs(i, visited | (1 << i)) + weight[lastVisit][i]);
    }
  }

  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> weight[i][j];
    }
  }

  cout << dfs(0, 1) << "\n";
}
