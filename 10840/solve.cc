#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define PRIME_1 (4294967291)
#define PRIME_2 (4294967279)
#define PRIME_3 (4294967231)

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

vector<pair<pair<uint64_t, uint64_t>, int>> compute_hash(string& s) {
  vector<pair<pair<uint64_t, uint64_t>, int>> hashes;
  for (int i = 0; i < s.size(); i++) {
    uint64_t h1 = 1, h2 = 1;
    for (int j = i; j < s.size(); j++) {
        h1 = (h1 * primes[s[j] - 'a']) % PRIME_1;
        h2 = (h2 * primes[s[j] - 'a']) % PRIME_2;

        hashes.push_back(make_pair(make_pair(h1, h2), j - i + 1));
        //printf("h1: %p %p %p\n", h1, h2, h);
    }
  }
  sort(hashes.begin(), hashes.end());
  return hashes;
}

int main() {
  genPrime();
  string s1, s2;
  cin >> s1;
  cin >> s2;

  vector<pair<pair<uint64_t, uint64_t>, int>> hashes1 = compute_hash(s1);
  // printf("\n");
  vector<pair<pair<uint64_t, uint64_t>, int>> hashes2 = compute_hash(s2);
  int maxlen = 0;

  int i = 0, j = 0;
  while (i < hashes1.size() && j < hashes2.size()) {
    auto h1 = hashes1[i].first;
    auto h2 = hashes2[j].first;

    // printf("%d %d %p, %p\n", i, j, h1, h2);
    if (h1 == h2) {
      //printf("%d, %d\n", hashes1[i].second, hashes2[j].second);
      assert(hashes1[i].second == hashes2[j].second);
      maxlen = max(maxlen, hashes1[i].second);
      i++;
      j++;
    }
    else if (h1 < h2)
      i++;
    else
      j++;
  }

  cout << maxlen << "\n";
}
