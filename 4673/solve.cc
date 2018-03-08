#include <iostream>

using namespace std;

bool has[10001];
int d(int i) {
  int s = i;
  while (i != 0) {
    s += i % 10;
    i /= 10;
  }
  return s;
}

int main() {
  for (int i = 0; i <= 10000; i++) {
    int x = d(i);
    if (x > 10000)
      continue;
    has[x] = true;
  }

  for (int i = 0; i <= 10000; i++)
    if (!has[i])
      cout << i << "\n";
}
