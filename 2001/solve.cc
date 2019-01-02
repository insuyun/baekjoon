#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> weights;
int jewel[101];
int cache[101][1<<14];

int main() {
  cin >> n >> m >> k;

  memset(jewel, -1, sizeof(jewel));

  for (int i = 0; i < k; i++) {
    int pos;
    cin >> pos;
    jewel[pos] = i;
  }

  weights.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    weights[a].push_back(make_pair(b, w));
  }

  queue<pair<int, int>> q;
  bool visited[101][1 << 14];
  visited[1][0] = true;
  q.push(make_pair(1, 0));

  int maxJewel = 0;

  while (!q.empty()) {
    int from  = q.front().first;
    int jewels = q.front().second;
    int numJewels = __builtin_popcount(jewels);
    q.pop();

    // cout << from << ", " << jewels << "\n";
    visited[from][jewels] = true;
    if (from == 1)
      maxJewel = maxJewel | jewels;

    // grasp jewel
    if (jewel[from] != -1) {
      int newJewels = jewels | (1 << jewel[from]);
      if (!visited[from][newJewels]) {
        visited[from][newJewels] = true;
        q.push(make_pair(from, newJewels));
      }
    }

    for (auto edge : weights[from]) {
      int to = edge.first;
      int weight = edge.second;

      if (numJewels > weight)
        continue;

      if (!visited[to][jewels]) {
        visited[to][jewels] = true;
        q.push(make_pair(to, jewels));
      }
    }
  }

  cout << __builtin_popcount(maxJewel) << "\n";
}
