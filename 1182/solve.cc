#include <iostream>

using namespace std;

int n, s;
int numbers[21];

int count(int sum, int index) {
//  cout << sum << ", " << index << "\n";
  if (index >= n) {
    if (sum == s)
      return 1;
    else
      return 0;
  }

  int c = count(sum + numbers[index], index + 1);
  c += count(sum, index + 1);
  return c;
}

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  int c = count(0, 0);
  if (s == 0)
    c -= 1;
  cout << c << "\n";
}

