#include <iostream>
#include <queue>

using namespace std;

int n, k;

vector<int> friends[21];

int main() {
  int64_t good_friend = 0;

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    friends[name.size()].push_back(i);
  }

  for (int i = 0; i <= 20; i++) {
    queue<int> q;
    vector<int>& v = friends[i];

    for (int cur : v) {
      while (!q.empty()) {
        int front = q.front();
        if (cur - front <= k)
          break;
        good_friend += q.size() - 1;
        q.pop();
      }

      q.push(cur);
    }

    while (!q.empty()) {
      good_friend += q.size() - 1;
      q.pop();
    }
  }

  cout << good_friend << "\n";
}
