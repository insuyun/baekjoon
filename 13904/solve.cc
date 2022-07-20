#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

#define MAX_N 1000

int N;
int d[MAX_N], w[MAX_N];
bool used[MAX_N];

int main() {
  int total = 0;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> d[i] >> w[i];

  for (int i = N; i >= 1; i--) {
    int curIdx = -1;

    for (int j = 0; j < N; j++) {
      if (used[j]) continue;
      if (d[j] < i) continue;
      if (curIdx == -1
          || w[j] > w[curIdx]) curIdx = j;
    }

    if (curIdx == -1)
      continue;

      used[curIdx] = true;
      total += w[curIdx];
  }

  cout << total << "\n";
}
