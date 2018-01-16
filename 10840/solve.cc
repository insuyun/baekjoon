#include <string>
#include <iostream>

using namespace std;

const uint64_t kLargePrime = 9576890767;
int primes['z' - 'a' + 1];

int genPrime() {
  int n = 1;
  for (char i = 0; i <= 'z' - 'a'; i++) {
    while (true) {
      bool is_prime = true;
      n++;
      for (int j = 0; j < i; j++) {
        if (n % primes[j] == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime)
        break;
    }
//    std::cerr << (int)i << "th prime: " << n << "\n";
    primes[i] = n;
  }
}

int main() {
  genPrime();
  string s1, s2;
  cin >> s1;
  cin >> s2;

  int maxlen = 0;
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      uint64_t h1 = 1, h2 = 1;
      for (int k = 0; k < s1.size() - i && k < s2.size() - j; k++) {
        h1 = (h1 * primes[s1[i + k] - 'a']) % kLargePrime;
        h2 = (h2 * primes[s2[j + k] - 'a']) % kLargePrime;

        if (h1 == h2)
          maxlen = max(maxlen, k + 1);
      }
    }
  }
  cout << maxlen << "\n";
}
