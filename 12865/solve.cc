#include <iostream>
#include <cstring>

#define MAX_N 100
#define MAX_K 100000

using namespace std;
int N, K, W[MAX_N + 1], V[MAX_N + 1];
int total[MAX_K + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> W[i] >> V[i];
  }

  memset(total, 0, sizeof(total));

  for (int j = 0; j < N; j++) {
    for (int i = K; i >= W[j] ; i--) {
      int oldIdx = i - W[j];
      int newValue = total[oldIdx] + V[j];
      total[i] = max(total[i], newValue);
    }
  }

  cout << total[K] << "\n";
}
