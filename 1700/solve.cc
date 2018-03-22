#include <iostream>
#include <cassert>
#include <set>

using namespace std;
const int MAX = 101;
const int INF = 100000;
int n, k, ni;

int usages[MAX];

int get_next_usage(int start, int u) {
  for (int i = start; i < k; i++) {
    if (usages[i] == u)
      return i;
  }
  return INF;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> usages[i];
  }

  set<int> included;

  int num_swap = 0;

  for (int i = 0; i < k; i++) {
    int u = usages[i];
    // Already plugged
    if (included.find(u) != included.end())
      continue;

    if (included.size() < n) {
      included.insert(u);
    }
    else {
      int max_next = 0;
      int max_elem = -1;

      for (int v : included) {
        int v_next = get_next_usage(i + 1, v);
        if (v_next > max_next) {
          max_elem = v;
          max_next = v_next;
        }
      }

//      cout << "v:" << max_elem << " -> u:" << u << "\n";
      assert(max_elem != -1);
      included.erase(max_elem);
      included.insert(u);
      num_swap++;
    }
  }
  cout << num_swap << "\n";
}
