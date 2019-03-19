#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 300001

int p[MAX_N];
int q[MAX_N];

int ufind(int s) {
  if (p[s] < 0)
    return s;
  return p[s] = ufind(p[s]);
}

void umerge(int a, int b) {
  int pa = ufind(a);
  int pb = ufind(b);

  if (pa != pb) {
    p[pa] += p[pb];
    q[pa] += q[pb];
    p[pb] = pa;
  }

  q[pa]++;
}

bool mergeable(int a, int b) {
  int pa = ufind(a);
  int pb = ufind(b);

  int nNode = 0, nEdge = 0;

  if (pa == pb) {
    nNode = p[pa];
    nEdge = q[pa];
  }
  else {
    nNode = p[pa] + p[pb];
    nEdge = q[pa] + q[pb];
  }

  nEdge++;

  return -nNode >= nEdge;
}

int main() {
  int n, l;
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l;

  memset(p, -1, sizeof(p));

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    bool r = mergeable(a, b);
    if (r) {
      cout << "LADICA\n";
      umerge(a, b);
    }
    else
      cout << "SMECE\n";
  }
}
