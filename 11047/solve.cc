#include <iostream>

using namespace std;

const int MAX = 11;

int n, k;
int coins[MAX];

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  int rem = k;
  int ncoins = 0;
  for (int i = n - 1; i >= 0; i--) {
    ncoins += rem / coins[i];
    rem %= coins[i];
  }

  cout << ncoins << "\n";
}
