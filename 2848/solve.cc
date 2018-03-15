#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMax = 'z' - 'a' + 1;

int t;
bool contains[kMax];
vector<int> edges[kMax];
int indegree[kMax];
string strings[101];

void mark_contains(std::string& s) {
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (!contains[c]) {
      contains[c] = true;
      t++;
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> strings[i];
    mark_contains(strings[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool broken = false;
      string& s1 = strings[i];
      string& s2 = strings[j];
      for (int k = 0; k < min(s1.size(), s2.size()); k++) {
        if (s1[k] != s2[k]) {
          edges[s1[k] - 'a'].push_back(s2[k] - 'a');
          //        cout << s1[k] << " -> " << s2[k] << "\n";
          indegree[s2[k] - 'a']++;
          broken = true;
          break;
        }
      }

      // Special case: ab a --> return !
      if (!broken && s1.size() > s2.size()) {
        cout << "!\n";
        return 0;
      }
    }
  }

  queue<int> q;

  // add indegree 0
  for (int i = 0; i < kMax; i++) {
    if (contains[i] && indegree[i] == 0)
      q.push(i);
  }

  vector<int> order;
  bool ambiguous = false;
  while (!q.empty()) {
    if (q.size() > 1) {
      ambiguous = true;
      break;
    }

    int u = q.front();
    q.pop();

    for (int v : edges[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }

    order.push_back(u);
  }

//   cout << "t: " << t << "\n";

  if (ambiguous)
    cout << "?\n";
  else if (order.size() != t)
    cout << "!\n";
  else {
    for (auto i : order)
      cout << (char)(i + 'a');
    cout << "\n";
  }
}
