#include <iostream>

using namespace std;

const int MAX = 100001;

int n, m;
int lengths[MAX];

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> lengths[i];

  int lo = 0;
  int hi = 1000000001;

  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;

    int count = 1;
    int sum = 0;
    bool cannot_fit_in = false;

    for (int i = 0; i < n; i++) {
      if (lengths[i] > mid)
        cannot_fit_in = true;

      if (sum + lengths[i] > mid) { // cannot be in
        sum = lengths[i];
        count++;
      }
      else
        sum += lengths[i];
    }

    //cout << "mid: " << mid << "\n";
    //cout << "count: " << count << ", m=" << m << "\n";
    // mid can work
    if (count <= m && !cannot_fit_in)
      hi = mid;
    else
      lo = mid;
    //cout << lo << ", " << hi << "\n";
  }

  cout << hi << "\n";
}
