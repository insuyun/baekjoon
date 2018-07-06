#include <iostream>

using namespace std;

int n, k, limit;
int cache[1000001][11];

int p10(int x) {
  int p = 1;
  for (int i = 0; i < x; i++) {
    p *= 10;
  }
  return p;
}

int replace(int n, int k) {
  if (cache[n][k] != 0)
    return cache[n][k];

  //cout << "n:" << n << ", k: " << k << "\n";
  if (k == 0)
    return n;

  int mval = -1;
  for (int i = 0; i < limit; i++) {
    int p_i = p10(i);
    int d_i = (n / p_i) % 10;

    for (int j = i + 1; j < limit; j++) {
      int p_j = p10(j);
      int d_j = (n / p_j) % 10;

      // no leading zero == 0
      if (d_i == 0 && j == limit - 1)
        continue;

      int new_n = n - d_j * p_j - d_i * p_i + d_j * p_i + d_i * p_j;
      mval = max(replace(new_n, k - 1), mval);
    }
  }
  cache[n][k] = mval;
  return mval;
}

int main() {
  cin >> n >> k;
  while (1)  {
    if (p10(limit) > n)
      break;
    limit++;
  }
  cout << replace(n, k) << "\n";
}
