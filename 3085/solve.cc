#include <iostream>

using namespace std;

int n;
char board[50][50];

int get_max(int x, int y) {
  int row = 1;
  for (int i = x - 1; i >= 0; i--) {
    if (board[x][y] == board[i][y])
        row++;
    else
      break;
  }

  for (int i = x + 1; i < n; i++) {
    if (board[x][y] == board[i][y])
        row++;
    else
      break;
  }

  int col = 1;
  for (int i = y - 1; i >= 0; i--) {
    if (board[x][y] == board[x][i])
        col++;
    else
      break;
  }

  for (int i = y + 1; i < n; i++) {
    if (board[x][y] == board[x][i])
        col++;
    else
      break;
  }

  // cout << "x: " << x << ", y: " << y << ": " << row << ", " << col << "\n";
  return max(col, row);
}

void swap(int x1, int y1, int x2, int y2) {
  char tmp = board[x1][y1];
  board[x1][y1] = board[x2][y2];
  board[x2][y2] = tmp;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  // 1. get logest without swap
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m = max(m, get_max(i, j));
    }
  }

  // 2. get longest with swap
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != n - 1) {
        swap(i, j, i + 1, j);
        m = max(m, get_max(i, j));
        m = max(m, get_max(i + 1, j));
        swap(i, j, i + 1, j);
      }

      if (j != n - 1) {
        swap(i, j, i, j + 1);
        m = max(m, get_max(i, j));
        m = max(m, get_max(i, j + 1));
        swap(i, j, i, j + 1);
      }
    }
  }
  cout << m << "\n";
}
