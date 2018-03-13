#include <iostream>

using namespace std;

bool visited[40 + 1];
int num[40 + 1][2];

int main() {
  num[0][0] = 1;
  num[0][1] = 0;

  num[1][0] = 0;
  num[1][1] = 1;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 2; j++)
        num[i][j] = num[i - 1][j] + num[i - 2][j];
    }
    cout << num[n][0] << " " << num[n][1] << "\n";
  }
}
