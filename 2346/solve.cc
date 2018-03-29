#include <iostream>
#include <list>

using namespace std;

const int MAX = 10001;
int n;
int next_val[MAX];

list<int>::iterator prev(list<int>::iterator it, list<int>& l) {
  if (it == l.begin())
    return --l.end();
  else
    return --it;
}

list<int>::iterator next(list<int>::iterator it, list<int>& l) {
  it++;
  if (it == l.end())
    return l.begin();
  else
    return it;
}

int main() {
  cin >> n;
  list<int> l;

  for (int i = 1; i <= n; i++) {
    cin >> next_val[i];
    l.push_back(i);
  }

  list<int>::iterator it = l.begin();

  while (true) {
    int x = *it;
    cout << x << " ";
    int off = next_val[x];
    list<int>::iterator tmp = next(it, l);
    l.erase(it);

    if (l.size() == 0)
      break;

    it = tmp;
    if (off > 0) {
      for (int i = 0; i < off - 1; i++)
        it = next(it, l);
    }
    else {
      for (int i = 0; i < -off; i++)
        it = prev(it, l);
    }
  }
}
