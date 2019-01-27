#include <iostream>
#include <queue>
#include <stdint.h>

int primes[101];

using namespace std;

int main() {
  priority_queue<int64_t> pq;
  int k, n;

  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> primes[i];
    pq.push(-primes[i]);
  }

  int uniques = 0;
  int64_t prev = -1;
  int64_t q;

  while (uniques != n) {
    q = pq.top();
    pq.pop();

    if (prev == q)
      continue;

    prev = q;
    uniques++;

    for (int j = 0; j < k; j++)
      pq.push(q * primes[j]);
  }

  cout << -q << "\n";
}
