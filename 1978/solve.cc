#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 1001

bool isPrime[MAX_N];


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  // Build isPrime array
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i < MAX_N; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * 2; j < MAX_N; j += i) {
      isPrime[j] = false;
    }
  }

  int c = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (isPrime[v]) {
      // cout << v << " is prime" << "\n";
      c++;
    }
    else {
      // cout << v << " is not prime" << "\n";
    }
  }

  cout << c << "\n";
}
