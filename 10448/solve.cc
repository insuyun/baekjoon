#include <iostream>
#include <vector>

using namespace std;

vector<int> tri;

bool check(int x) {
  for (int i = 0; i < tri.size(); i++) {
    for (int j = 0; j < tri.size(); j++){
      for (int k = 0; k < tri.size(); k++) {
        if(tri[i] + tri[j] + tri[k] == x)
          return true;
      }
    }
  }
  return false;
}

int main() {
  int n = 1;
  while (true) {
    int tn = n * (n + 1) / 2;
    if (tn > 1000)
      break;
    tri.push_back(tn);
    n++;
  }

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << check(k) << "\n";
  }
}
