#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 100000;
int n;
int numbers[MAX + 1][2];
int sum[MAX + 1][3];

int compute(int i, int j) {
  if (i == 0)
    return 0;

  if (sum[i][j] != -1)
    return sum[i][j];

  int r = 0;
  if (j == 0)
    r = max(compute(i - 1, 0), max(compute(i - 1, 1), compute(i - 1, 2)));
  else if (j == 1)
    r = max(compute(i - 1, 2), compute(i - 1, 0)) + numbers[i][0];
  else if (j == 2)
    r = max(compute(i - 1, 1), compute(i - 1, 0)) + numbers[i][1];
  else
    assert(false);

  sum[i][j] = r;
  return r;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    memset(sum, -1, sizeof(sum));
    for (int j = 0; j < 2; j++) {
      for (int i = 1; i <= n; i++)
        cin >> numbers[i][j];
    }

    int m = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 3; j++)
        m = max(m, compute(i, j));
    cout << m << "\n";
  }
}
