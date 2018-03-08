#include <iostream>
#include <cstring>

using namespace std;

int n;
int num[1001][10];

int compute(int start, int beg) {
  if (start == n)
    return 1;

  if (num[start][beg] != -1)
    return num[start][beg];

  int sum = 0;
  for (int i = beg; i < 10; i++)
      sum = (sum + compute(start + 1, i)) % 10007;
  num[start][beg] = sum;
  return sum;
}

int main() {
  cin >> n;
  memset(num, -1, sizeof(num));

  cout << compute(0, 0) << "\n";
}
