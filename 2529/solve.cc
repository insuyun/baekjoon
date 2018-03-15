#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMax = 11;
int n;
vector<int> edges1[kMax];
vector<int> edges2[kMax];

void f(vector<int>* edges, bool bigger) {
  priority_queue<int> pq;

  int indegree[n + 1] = {};

  for (int i = 0; i < n + 1; i++) {
    for (int j : edges[i])
      indegree[j]++;
  }

  for (int i = 0; i < n + 1; i++) {
    if (indegree[i] == 0)
      pq.push(-i);
  }

  char assign[n + 1];
  int num = bigger ? 9 : 0;

  while (!pq.empty()) {
    int u = -pq.top();
    pq.pop();

    for (int v : edges[u]) {
      indegree[v]--;
      if (indegree[v] == 0)
        pq.push(-v);
    }
    assign[u] = num + '0';
    if (bigger)
      num--;
    else
      num++;
  }

  for (int i = 0; i < n + 1; i++)
    cout << assign[i];
  cout << "\n";

}

int main() {
  cin >> n;

  // make edge from smaller to larger
  for (int i = 0; i < n; i++) {
    char ineq;
    cin >> ineq;
    if (ineq == '>')  {
      // x > y
//      cout << i + 1 << "-> " << i << "\n";
      edges1[i + 1].push_back(i);
      edges2[i].push_back(i + 1);
    }
    else {
 //     cout << i << "-> " << i + 1 << "\n";
      edges1[i].push_back(i + 1);
      edges2[i + 1].push_back(i);
    }
  }

  f(edges2, true);
  f(edges1, false);
}
