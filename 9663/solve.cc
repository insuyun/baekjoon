#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
bool board[16][16];

const int offset[3][2] = {
  1, 0,
  1, 1,
  1, -1,
};

void add_queen(vector<pair<int, int>>& change, int x, int y) {
//  cout << "x: " << x << ", y:" << y << "\n";

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < n; j++) {
      int nx = x + offset[i][0] * j;
      int ny = y + offset[i][1] * j;

      if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//        cout << "nx: " << nx << ", ny:" << ny << ", board: " << board[nx][ny] << "\n";
        if (!board[nx][ny]) {
//          cout << "[APPLY] nx: " << nx << ", ny: " << ny << "\n";
          change.push_back(make_pair(nx, ny));
          board[nx][ny] = true;
        }
      }
    }
  }

  //getc(stdin);
}

void remove_queen(vector<pair<int, int>>& change) {
//  cout << "REMOVE_QUEEN\n";
  for (auto p : change)
    board[p.first][p.second] = false;
}

int nqueen(int c, int x, int y) {
//  cout << "nqueen(" << c << ", " << x << ", " << y << ")\n";
  if (c == n)
    return 1;

  int sum = 0;

  for (int j = 0; j < n; j++) {
    if (!board[x][j]) {
      vector<pair<int, int>> change;
      add_queen(change, x, j);
      sum += nqueen(c + 1, x + 1, j);
      remove_queen(change);
    }
  }

  return sum;
}

int main() {
  cin >> n;
  cout << nqueen(0, 0, 0) << "\n";
}
