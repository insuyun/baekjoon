#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 10000000;
const int MAX = 31 * 31 * 31;

bool node[31][31][31];
bool visited[31][31][31];
int dist[31][31][31];
int sx, sy, sz, ex, ey, ez;

int l, r, c;

int to_id(int x, int y, int z) {
  return z * (r + 1) * (c + 1) + y * (c + 1) + x;
}

void from_id(int id, int* x, int *y, int *z) {
  *x = id % (c + 1);
  id /= (c + 1);
  *y = id % (r + 1);
  id /= (r + 1);
  *z = id;
}

pair<int, pair<int, pair<int, int>>> mp(int v, int x, int y, int z) {
  return make_pair(0, make_pair(x, make_pair(y, z)));
}

void insert_to_queue(queue<int> &q, int x1, int y1, int z1, int x2, int y2, int z2) {
//  fprintf(stderr, "x2: %d, y2: %d, z2: %d\n", x2, y2, z2);
  if (x2 == 0
      || y2 == 0
      || z2 == 0
      || x2 > c || y2 > r || z2 > l
      || !node[x2][y2][z2]
      || visited[x2][y2][z2])
    return;

  visited[x2][y2][z2] = true;
  dist[x2][y2][z2] = dist[x1][y1][z1] + 1;
  q.push(to_id(x2, y2, z2));
}

int bfs() {
  queue<int> q;
  q.push(to_id(sx, sy, sz));
  visited[sx][sy][sz] = true;

  int x, y, z;
  from_id(to_id(sx, sy, sz), &x, &y, &z);

  while (!q.empty()) {
    int id = q.front();
    q.pop();

    int x, y, z;
    from_id(id, &x, &y, &z);
    insert_to_queue(q, x, y, z, x - 1, y, z);
    insert_to_queue(q, x, y, z, x + 1, y, z);
    insert_to_queue(q, x, y, z, x, y - 1, z);
    insert_to_queue(q, x, y, z, x, y + 1, z);
    insert_to_queue(q, x, y, z, x, y, z - 1);
    insert_to_queue(q, x, y, z, x, y, z + 1);
  }
}

int main() {
  while (true) {
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    memset(node, 0, sizeof(node));

    cin >> l >> r >> c;
//    fprintf(stderr, "Metadata: %d %d %d\n", l, r, c);
    if (l == 0 && r == 0 && c == 0)
      break;

    for (int k = 1; k <= l; k++) {
      for (int j = 1; j <= r; j++) {
        for (int i = 1; i <= c; i++) {
          char c;
          cin >> c;
          if (c != '#') {
//            fprintf(stderr, "Add node %d, %d, %d\n", i, j, k);
            node[i][j][k] = true;
          }
          if (c == 'S') {
            sx = i; sy = j; sz = k;
          }
          if (c == 'E') {
            ex = i; ey = j; ez = k;
          }
        }
      }
    }

    bfs();

    if (dist[ex][ey][ez] == 0)
      cout << "Trapped!\n";
    else {
      cout << "Escaped in " << dist[ex][ey][ez] << " minute(s).\n";
    }
  }
}
