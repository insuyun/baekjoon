#include <iostream>

using namespace std;

bool data[64][64];
int n;

const int UNKNOWN = -1;
const int UNDECIDABLE = 2;

string quad_tree(int x, int y, int size) {
  if (size == 1) {
    return to_string(data[x][y]);
  }

  string subtree[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      subtree[i][j] = quad_tree(x + size / 2 * i, y + size / 2 * j, size / 2);
    }
  }

  // compress?
  string s = subtree[0][0];
  // cout << "x: " << x << ", y:" << y << ", size: " << size << "\n";
  // cout << "s: " << s << "\n";
  bool compressable = s.size() == 1;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (s != subtree[i][j])
        compressable = false;
    }
  }

  if (compressable)
    return s;
  else {
    // Not compressable
    string s = "(";
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        s += subtree[i][j];
      }
    }
    s += ")";
    return s;
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      data[i][j] = c - '0';
    }
  }

  cout << quad_tree(0, 0, n) << "\n";
}
