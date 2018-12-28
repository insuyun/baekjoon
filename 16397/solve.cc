#include <iostream>
#include <queue>

using namespace std;

#define MAX 100000

int bvalue(int c) {
  if (c == 0)
    return 0;

  int n = 1;
  c *= 2;
  while (true) {
    if (n * 10 > c)
      break;
    n *= 10;
  }

  c -= n;
  return c;
}

bool visited[100000];

int main() {
//  cout << bvalue(0) << "\n";
//  cout << bvalue(123) << "\n";
//  cout << bvalue(5) << "\n";
//  cout << bvalue(3) << "\n";

  int n, t, g;
  cin >> n >> t >> g;

  queue<int> q;
  q.push(n);
  visited[n] = true;

  int p = 0;

  while (!q.empty() && p <= t) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int c = q.front();
      // printf("%d\n", c);
      if (c == g) {
        printf("%d\n", p);
        exit(0);
      }
      q.pop();

      // A
      if (c + 1 < MAX && !visited[c+1]) {
        visited[c + 1] = true;
        q.push(c + 1);
      }

      // B
      if (c * 2 < MAX) {
        int b = bvalue(c);
        if (!visited[b]) {
          visited[b] = true;
          q.push(b);
        }
      }
    }
    p++;
  }

  //printf("%d\n", p);
  printf("ANG\n");
}
