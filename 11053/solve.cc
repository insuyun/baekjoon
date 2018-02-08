#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    numbers.push_back(v);
  }

  vector<int> sum(n, 0);

  for (int i = n - 1; i >= 0; i--) {
    int next = 0;
    for (int j = i + 1; j < n; j++) {
      if (numbers[j] > numbers[i])
        next = max(sum[j], next);
    }
    sum[i] = next + 1;
  }

  int res = 0;
  for (int i = 0; i < n; i++)
    res = max(res, sum[i]);

  cout << res << "\n";
}
