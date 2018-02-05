#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector< vector<int> > cache;
  cache.push_back(vector<int>(3, 0));

  for (int i = 1; i <= n ; i++) {
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    cache.push_back(vector<int>(3, 0));

    for (int j = 0; j < 3; j++) {
      int j1 = (j + 1) % 3;
      int j2 = (j + 2) % 3;
      cache[i][j] = min(cache[i - 1][j1], cache[i - 1][j2]) + v[j];
    }
  }


  int r = INT_MAX;
  for (int i = 0; i < 3; i++)
    r = min(r, cache[n][i]);

  cout << r << endl;
}
