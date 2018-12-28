#include <queue>
#include <iostream>

using namespace std;

bool visited[15 * 2][15 * 2];
double sum = 0;
int n, prob[4];

int off[4][2] = {
  1, 0,
  -1, 0,
  0, 1,
  0, -1
};

void dfs(int s, int x, int y, double p) {
//  printf("Enter %d: %d %d\n", s, x, y);

  if (s > n)
    return;

  if (visited[x][y]) {
//    printf("Hit %d: %d %d %lf\n", s, x, y, p);
    sum += p;
    return;
  }

  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    dfs(s + 1, x + off[i][0], y + off[i][1], p * (prob[i] / 100.0));
  }

  visited[x][y] = false;

//  printf("Exit %d: %d %d\n", s, x, y);
}

int main() {
  cin >> n;
  for (int i = 0; i < 4; i++)
    cin >> prob[i];

  dfs(0, 15, 15, 1);

  printf("%.10lf\n", 1-sum);
//  for (int i = 0; i < 4; i++) {
//    printf("%d %d\n", off[i][0], off[i][1]);
//  }
}
