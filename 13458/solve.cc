#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

#define MAX_N 1000000

int64_t N, A[MAX_N + 1], B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> B >> C;

  int64_t total = 0;

  for (int i = 0; i < N; i++) {
    int c = A[i];
    A[i] -= B;
    total += 1;
    if (A[i] <= 0)
      continue;

    total += ((A[i] + C - 1) / C);
  }

  cout << total << "\n";
}
