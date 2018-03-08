#include <iostream>
#include <vector>

using namespace std;

int n, m;

int values[100000 + 1];

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> values[i];
  }

  // 1. Get the M value from the last
  int csum = 0;
  for (int i = n - 1; i > n - m - 1; i--) {
    csum += values[i];
  }

  int max_value = csum;
  int rear = n - 1;
  int remainder = 0;
  for (int i = n - m - 1; i >= 0; i--) {
    remainder += values[rear--];
    csum += values[i];
    if (remainder < 0) {
      csum -= remainder;
      remainder = 0;
    }
    max_value = max(csum, max_value);
  }

  if (max_value < 0)
    printf("0\n");
  else
    printf("%d\n", max_value);
}
