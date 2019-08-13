#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>

#define MAX_N 1000000

using namespace std;

int n;
vector<int> numbers;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    numbers.push_back(v);
  }

  bool is_prime[MAX_N];
  memset(is_prime, 1, sizeof(is_prime));

  for (int i = 2; i < int(sqrt(MAX_N)) + 1; i++) {
    if (!is_prime[i])
      continue;
    //printf("%d\n", i);
    getchar();
    for (int j = i * i; j < MAX_N; j += i) {
      is_prime[j] = false;
    }
  }

  vector<map<int, int>> num_primes;
  num_primes.resize(n);

  // count # of primes
  for (int i = 0; i < n; i++) {
    int v = numbers[i];
    for (int j = 2; j < MAX_N; j++) {
      if (!is_prime[j])
        continue;

      int c = v;
      while (c % j == 0) {
        if (num_primes[i].find(j) == num_primes[i].end())
          num_primes[i][j] = 0;
        num_primes[i][j]++;
        c /= j;
      }
    }
  }

  int score = 1;
  int trials = 0;
  for (int j = 2; j < MAX_N; j++) {
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (num_primes[i].find(j) != num_primes[i].end()) {
        total += num_primes[i][j];
      }
    }

    if ((total / n) != 0) {
      // we have enough one..
      for (int k = 0; k < total / n; k++)
        score *= j;

      for (int i = 0; i < n; i++) {
        int count = 0;
        if (num_primes[i].find(j) != num_primes[i].end()) {
          count = num_primes[i][j];
        }

        if (count < total / n) {
          trials += (total / n) - count;
        }
      }
    }
  }

  printf("%d %d\n", score, trials);
}
