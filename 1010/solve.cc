#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<int64_t>> cache;

int64_t bridge(int i, int j) {
  if (i == N)
    return 1;

  int value = cache[i][j];
  if (value != -1)
    return value;

  value = 0;
  for (int k = j + 1; k <= M; k++)
    value += bridge(i + 1, k);

  cache[i][j] = value;
  return cache[i][j];
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> N;
    cin >> M;

    cache.clear();
    for (int i = 0; i < N; i++)
      cache.push_back(vector<int64_t>(M + 1, -1));

    cout << bridge(0, 0) << "\n";
  }
}
