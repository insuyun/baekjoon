#include <iostream>

using namespace std;

int r, c;
char board[21][21];
bool visited[256];

int off[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int alph(int x, int y, int nvisit) {
//  cout << "x: " << x << ", y:" << y << ", nvisit: " << nvisit << "\n";
  int maxval = nvisit;

  for (int i = 0; i < 4; i++) {
    int nx = x + off[i][0];
    int ny = y + off[i][1];

    if (nx < r && ny < c && nx >= 0 && ny >= 0) {
      char ch = board[nx][ny];
      if (!visited[ch]) {
        visited[ch] = true;
        maxval = max(alph(nx, ny, nvisit + 1), maxval);
        visited[ch] = false;
      }
    }
  }
  return maxval;
}

int main() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
    }
  }

  visited[board[0][0]] = true;
  cout << alph(0, 0, 0) + 1 << "\n";
}
