#include <iostream>

using namespace std;

const int MAX = 10001;
int budgets[MAX];

int n, m;

int main() {
  int l = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> budgets[i];
    l = max(l, budgets[i]);
  }

  cin >> m;

  int lo = 0, hi = 1000000001;

  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (budgets[i] > mid)
        sum += mid;
      else
        sum += budgets[i];
    }

    if (sum > m)
      hi = mid;
    else
      lo = mid;
  }

  if (lo > l)
    cout << l << "\n";
  else
    cout << lo << "\n";
}
