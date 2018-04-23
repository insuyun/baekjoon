#include <iostream>
#include <queue>

using namespace std;

int main() {
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  bool visited[1000001] = {};
  queue<int> q;
  visited[s] = true;
  q.push(s);

  int step = 0;
  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      int v = q.front();
      q.pop();

      if (v == g) {
        printf("%d\n", step);
        return 0;
      }

      if (v + u <= f && !visited[v + u]) {
        q.push(v + u);
        visited[v + u] = true;
      }

      if (v - d >= 1 && !visited[v - d]) {
        q.push(v - d);
        visited[v - d] = true;
      }
    }

    step++;
  }

  printf("use the stairs\n");
}
