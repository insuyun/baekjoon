#include <iostream>
#include <algorithm>

using namespace std;

const int kMax = 1001;
int n, l;
int pos[kMax];

int main() {
  cin >> n >> l;

  for (int i = 0; i < n; i++)
    cin >> pos[i];

  // sort
  sort(pos, pos + n);

  int tapes = 0;
  int next = 0;
  for (int i = 0; i < n; i++) {
    if (next <= pos[i]) {
      next = pos[i] + l;
      tapes++;
    }
  }

  cout << tapes << "\n";
}
