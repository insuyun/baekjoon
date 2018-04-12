#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

bool map[26][26];
bool visited[26][26];

int n, c;

const int offset[4][2] = {
  1, 0,  -1, 0,
  0,  1,  0, -1
};

bool valid(int x, int y) {
  // fprintf(stderr, "valid(%d, %d)\n", x, y);
  return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y) {
  // fprintf(stderr, "dfs(%d, %d)\n", x, y);
  assert(map[x][y] && !visited[x][y]);
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    //fprintf(stderr, "offset[%d][0]: %d, offset[%d][1]: %d\n", i, offset[i][0], i,
    //    offset[i][1]);
    int nx = x + offset[i][0];
    int ny = y + offset[i][1];
    if (valid(nx, ny) && !visited[nx][ny] && map[nx][ny])
      dfs(nx, ny);
  }
  c++;
}

int main() {
  vector<int> numbers;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      map[i][j] = c - '0';
      //fprintf(stderr, "map[%d][%d]: %d\n", i, j, map[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] && !visited[i][j]) {
        dfs(i, j);
        numbers.push_back(c);
        c = 0;
      }
    }
  }

  cout << numbers.size() << "\n";
  sort(numbers.begin(), numbers.end());
  for (int num : numbers)
    cout << num << "\n";
}
