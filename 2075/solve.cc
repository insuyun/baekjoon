#include <iostream>
#include <queue>
#define MAX 1501

int arr[MAX][MAX];
int indicies[MAX];

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, int>> pq;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    pq.push(make_pair(arr[n-1][i], i));
    indicies[i] = n - 2;
  }

  for (int i = 0; i < n - 1; i++) {
    auto p = pq.top();
//    cout << p.first << "\n";
    pq.pop();

    int index = indicies[p.second];
    if (index >= 0) {
      pq.push(make_pair(arr[index][p.second], p.second));
      indicies[p.second]--;
    }
  }

  cout << pq.top().first << "\n";
}
