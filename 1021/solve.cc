#include <iostream>
#include <list>

using namespace std;

const int MAX = 51;
int n, m;
int elems[MAX];

list<int>::iterator next(list<int>::iterator it, list<int>& l) {
  it++;
  if (it == l.end())
    return l.begin();
  else
    return it;
}

int main() {
  cin >> n >> m;
  list<int> l;

  int sum = 0;
  for (int i = 0; i < m; i++)
    cin >> elems[i];

  for (int i = 1; i <= n; i++)
    l.push_back(i);

  list<int>::iterator it = l.begin();
  for (int i = 0; i < m; i++) {
    int j = 0;
    while (*it != elems[i]) {
      it = next(it, l);
      j++;
    }
    sum += min(j, (int)l.size() - j);

    list<int>::iterator nit = next(it, l);
    l.erase(it);
    it = nit;
  }

  cout << sum << "\n";
}
