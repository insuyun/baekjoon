#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int kMaxN = 123456 * 2 + 1;

int main() {
  vector<int> primes;
  bool is_prime[kMaxN];
  memset(is_prime, 1, sizeof(is_prime));

  for (int i = 2; i < int(sqrt(kMaxN)) + 1; i++) {
    if (!is_prime[i])
      continue;

    for (int j = i * i; j < kMaxN; j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = 2; i < kMaxN; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    auto it1 = std::upper_bound(primes.begin(), primes.end(), n);
    auto it2 = std::upper_bound(primes.begin(), primes.end(), 2 * n);
    cout << (it2 - it1) << "\n";
  }

}
