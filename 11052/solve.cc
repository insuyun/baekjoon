#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> sets;

  sets.push_back(0);
  for (int i = 0; i < n; i++) {
    int set_price;
    cin >> set_price;
    sets.push_back(set_price);
  }

  vector<int> value(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int v = 0;
    for (int j = 1; i - j >= 0; j++) {
      v = max(value[i - j] + sets[j], v);
    }
    value[i] = v;
  }

  cout << value[n] << "\n";
}
