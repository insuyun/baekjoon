#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int64_t> prices;
vector<vector<pair<int64_t, int64_t>>> weights;
vector<vector<int64_t>> warshall;
vector<vector<pair<int64_t, int64_t>>> new_weights;

#define INF INT64_MAX

vector<int64_t>
dijkstra(int src, vector<vector<pair<int64_t, int64_t>>>& w) {
    vector<int64_t> dist;
    dist.resize(N + 1, INF);
    dist[src] = 0; // Distant from source to source

    priority_queue<pair<int64_t, int64_t>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
      int64_t cost = -pq.top().first;
      int here = pq.top().second;
      pq.pop();

      if (dist[here] < cost) continue;

      for (int i = 0; i < w[here].size(); i++) {
        int there = w[here][i].first;
        int64_t new_cost = cost + w[here][i].second;
        if (dist[there] > new_cost) {
          dist[there] = new_cost;
          pq.push(make_pair(-new_cost, there));
        }
      }
    }

    return dist;
}
#if 0
vector<vector<int>> floyd() {
  vector<vector<int>> res;
  res.resize(N + 1);
  for (int i = 0; i < N + 1; i++) {
    res[i].resize(N + 1, INF);
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 0; j < weights[i].size(); j++) {
      res[i][weights[i][j].first] = weights[i][j].second;
    }
  }
  for (int i = 0; i < N + 1; i++)
    res[i][i] = 0;

  // Run Floyd-Warshall Algorithm
  for (int k = 1; k < N + 1; k++) {
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        if (res[i][j] > res[i][k] + res[k][j]) {
          res[i][j] = res[i][k] + res[k][j];
        }
      }
    }
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      res[i][j] *= prices[i];
      cerr << "weight(" << i << "->" << j << "): " << res[i][j] << "\n";
    }
  }
  return res;
}
#endif

int main() {
  ios::sync_with_stdio(false);

  cin >> N >> M;
  // cerr << "N: " << N << ", M: " << M << "\n";

  prices.push_back(0); // Dummy
  for (int i = 1; i < N + 1; i++) {
    int v;
    cin >> v;
    prices.push_back(v);
    // cerr << "prices(" << i << "): " << v << "\n";
  }

  weights.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    // cerr << "weight(" << a << "->" << b << "): " << c << "\n";
    weights[a].push_back(make_pair(b, c));
    weights[b].push_back(make_pair(a, c));
  }


  // Run dijkstra N times to get all distances
  new_weights.resize(N + 1);
  for (int i = 1; i < N + 1; i++) {
    vector<int64_t> dist = dijkstra(i, weights);
    for (int j = 0; j < dist.size(); j++) {
      if (dist[j] != INF) {
        int64_t cost = dist[j] * prices[i];
        new_weights[i].push_back(make_pair(j, cost));
        // cerr << "new_weight(" << i << "->" << j << "): " << cost << "\n";
      }
    }
  }

  // floyd();

  cout << dijkstra(1, new_weights)[N] << "\n";
  return 0;
}
