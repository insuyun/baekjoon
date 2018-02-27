#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, k;
const int kMaxValue = 100000 + 2;
int elapsed_time[kMaxValue];
bool visited[kMaxValue];

void update(queue<int> &q, int index, int time) {
  if (index >= kMaxValue || index < 0)
    return;

  if (elapsed_time[index] != -1)
    return;
  elapsed_time[index] = time + 1;
  q.push(index);
}

void bfs() {
  queue<int> q;
  q.push(n);
  elapsed_time[n] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (visited[node])
      continue;

    visited[node] = true;
    int cur_time = elapsed_time[node];
    update(q, node + 1, cur_time);
    update(q, node - 1, cur_time);
    update(q, node * 2, cur_time);
  }
}

int main() {
  memset(elapsed_time, -1, sizeof(elapsed_time));
  memset(visited, 0, sizeof(visited));
  cin >> n >> k;
  bfs();
  printf("%d\n", elapsed_time[k]);
}
