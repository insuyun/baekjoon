#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> mapping;
vector<string> names;
int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // Make vector index starts from 1
  names.push_back("");
  cin >> n >> m;

  while(n--) {
    string name;
    cin >> name;
    mapping[name] = names.size();
    names.push_back(name);
  }

  while (m--) {
    string query;
    cin >> query;
    int q = strtoul(query.c_str(), NULL, 10);
    if (q == 0)
      cout << mapping[query] << "\n";
    else
      cout << names[q] << "\n";
  }
}
