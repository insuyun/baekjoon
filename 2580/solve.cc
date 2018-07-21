#include <iostream>
#include <vector>

using namespace std;

int board[9][9];

vector<int> find_candidate(int x, int y) {
  vector<int> v;
  for (int i = 1; i <= 9; i++) {
    bool invalid = false;
    // check vertical line
    for (int j = 0; j < 9; j++) {
      if (board[x][j] == i) {
        invalid = true;
        break;
      }
    }

    if (invalid)
      continue;

    // check horizontal line
    for (int j = 0; j < 9; j++) {
      if (board[j][y] == i) {
        invalid = true;
        break;
      }
    }

    if (invalid)
      continue;

    // check square
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (board[(x / 3) * 3 + j][(y / 3) * 3 + k] == i) {
          invalid = true;
          break;
        }
      }
    }

    if (invalid)
      continue;

    v.push_back(i);
  }

  return v;
}

bool find() {
  // find next empty one
  int x = -1, y = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        x = i;
        y = j;
        goto end;
      }
    }
  }
end:
  if (x == -1 && y == -1)
    return true;

  vector<int> v = find_candidate(x, y);
  for (auto c : v) {
    board[x][y] = c;
    if (find())
      return true;
  }

  board[x][y] = 0;
  return false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
    }
  }

  find();

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}
