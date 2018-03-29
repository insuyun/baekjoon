#include <iostream>
#include <cstring>

using namespace std;

char wheel[26];
bool used['Z' - 'A'];
int n, k, idx;

int main() {
  cin >> n >> k;
  memset(wheel, '?', sizeof(wheel));
  bool impossible = false;

  while (k--) {
    int off;
    char c;
    cin >> off >> c;

    idx = ((idx - off) % n + n) % n;
    if (wheel[idx] == '?') {
      wheel[idx] = c;
      if (used[c - 'A'])
        impossible = true;
      else
        used[c - 'A'] = true;
    }
    else {
      if (wheel[idx] != c)
        impossible = true;
    }
  }

  if (impossible)
    cout << "!\n";
  else {
    for (int i = 0; i < n; i++)
      cout << wheel[(idx + i) % n];
    cout << "\n";
  }
}
