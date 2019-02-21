#include <iostream>
#include <cstring>

#define MAX_N 1001

using namespace std;

int main() {
  int n, k;
  bool isPrime[MAX_N];
  memset(isPrime, 1, sizeof(isPrime));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  int c = 0;
  for (int i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    c++;

    if (c == k) {
      cout << i << "\n";
      return 0;
    }

    for (int j = i * 2; j <= n; j += i) {
      if (isPrime[j]) {
        //  cout << j << "\n";
        isPrime[j] = false;
        c++;
        if (c == k) {
         cout << j << "\n";
          return 0;
        }
      }
    }
  }
}
