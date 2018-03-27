#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1001;
const int INF = MAX;
int n;
int numbers[MAX];
int cache[MAX];

int get_max(int idx) {
  if (cache[idx] == -1) {
    int r = numbers[idx];
    for (int i = idx - 1; i >= 0; i--) {
      if (numbers[idx] > numbers[i])
        r = max(r, get_max(i) + numbers[idx]);
    }
    cache[idx] = r;
  }
  return cache[idx];
}

int main() {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  int m = 0;
  for (int i = 0; i < n; i++)
    m = max(get_max(i), m);
  cout << m << "\n";
}
