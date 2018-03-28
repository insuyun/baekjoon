#include <iostream>
#include <list>

using namespace std;

int n, m;

list<int>::iterator next(list<int>::iterator it, list<int>& l) {
  it++;
  if (it != l.end())
    return it;
  else
    return l.begin();
}

int main() {
  cin >> n >> m;
  list<int> l;

  for (int i = 1; i <= n; i++)
    l.push_back(i);

  list<int>::iterator it = l.begin();
  cout << "<";
  bool first = true;
  while (!l.empty()) {
    for (int i = 0; i < m - 1; i++)
      it = next(it, l);

    list<int>::iterator nit = next(it, l);
    if (first)
      first = false;
    else
      cout << ", ";
    cout << *it;
    l.erase(it);
    it = nit;
  }
  cout << ">";
}
