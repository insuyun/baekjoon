#include <iostream>

const int INF = 1000000;

using namespace std;

int m, n;

char board[51][51];

const char reverse(const char c) {
  if (c == 'W')
    return 'B';
  else
    return 'W';
}

int count(int x, int y) {
  const char colors[2] = {'W', 'B'};
  int r = INF;

  for (int k = 0; k < 2; k++) {
    int d = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
//        cout << board[x + i][y + j] << ", " << colors[(i + j + k) %2] << "\n";
        if (board[x + i][y + j] != colors[(i + j + k) % 2])
          d++;

      }
    }
    r = min(r, d);
//    cout << "x: " << x << ", y: " << y << " = " << r << "\n";
  }
  return r;
}

int main() {
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  int r = INF;
  for (int i = 0; i < m - 8 + 1; i++) {
    for (int j = 0; j < n - 8 + 1; j++) {
      r = min(r, count(i, j));
    }
  }

  cout << r <<"\n";
}
