#include <iostream>

using namespace std;

const int UNKNOWN = -2;
const int UNDECIDABLE = 2;

int numbers[2187 + 1][2187 + 1];
int counts[3];

int n;

int count_all(int x, int y, int size) {
  if (size == 1)
    return numbers[x][y]; // only one element

  int kinds[3][3];
  int kind = UNKNOWN; // not initialized
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      kinds[i][j] = count_all(x + size / 3 * i, y + size / 3 * j, size / 3);
      if (kind == UNKNOWN)
        kind = kinds[i][j];
      else if (kind != kinds[i][j])
        kind = UNDECIDABLE;
      else
        kind = max(kind, kinds[i][j]);
    }
  }

  if (kind == UNDECIDABLE) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int kind = kinds[i][j];
        if (kind != UNDECIDABLE)
          counts[kind + 1]++;
      }
    }
  }

  return kind;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> numbers[i][j];
    }
  }

  int kind = count_all(0, 0, n);
  if (kind != UNDECIDABLE)
    counts[kind + 1]++;

  cout << counts[0] << "\n"
    << counts[1] << "\n"
    << counts[2] << "\n";
}
