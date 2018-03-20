#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAX = 200000;

int n;
set<pair<int, int>> starts;
int finish_time[MAX];

int main() {
  cin >> n;

  for (int i = 0; i < n ; i++) {
    int s, e;
    cin >> s >> e;
    starts.insert(make_pair(s, i));
    finish_time[i] = e;
  }

  int c = 0;
  while (!starts.empty()) {
    auto it = starts.begin();
    while (it != starts.end()) {
      int next = finish_time[it->second];
//     cout << "start: " << it->first << "\n";
      starts.erase(it);
      it = starts.lower_bound(make_pair(next, 0));
    }
    c++;
  }

  cout << c << "\n";
}
