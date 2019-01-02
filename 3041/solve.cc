#include <iostream>

using namespace std;

char map[4][4];
char answer[4][4] = {
  'A', 'B', 'C', 'D',
  'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L',
  'M', 'N', 'O', '.'
};

int main() {
  int sum = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> map[i][j];

      for (int i2 = 0; i2 < 4; i2++) {
        for (int j2 = 0; j2 < 4; j2++) {
          if (map[i][j] == answer[i2][j2]
              && map[i][j] != '.') {
            sum += abs(i2 - i);
            sum += abs(j2 - j);
          }
        }
      }
    }
  }

  cout << sum << "\n";
}
