#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

uint64_t n, k;
uint64_t cache[0x1000];

uint64_t k_exp(uint64_t r) {
  assert((uint64_t)r < sizeof(cache) / sizeof(cache[0]));
  if (r == 0)
    return 1;
  if (cache[r] != (uint64_t)-1)
    return cache[r];
  cache[r] = k * k_exp(r - 1);
  return cache[r];
}

uint64_t geosum(uint64_t x) {
  return (k_exp(x) - 1) / (k - 1);
}

uint64_t calc_depth(uint64_t x) {
  // Find r which is (k^r - 1) >= x --> return r - 1;
  // cout << "calc_depth: " << x << "\n";
  for (uint64_t depth = 1;;depth++) {
    uint64_t gs = geosum(depth);
    if (x <= gs)
      return depth - 1;
  }
}

uint64_t parent(uint64_t x, uint64_t depth) {
  assert(depth != 0);
  uint64_t p = geosum(depth - 1) + (x - geosum(depth) - 1) / k + 1;
  // cout << "parent(" << x << ", " << depth << "): " << p << "\n";
  return p;
}

uint64_t calc_dis(uint64_t x, uint64_t y) {
  if (k == 1) {
    if (x > y)
      return x - y;
    else
      return y - x; // Specially handle when k == 1
  }

  uint64_t dx = calc_depth(x);
  uint64_t dy = calc_depth(y);

  int dis = 0;
  while (x != y) {
    if (dx > dy) {
      x = parent(x, dx);
      dx--;
      dis++;
    }
    else if (dy > dx) {
      y = parent(y, dy);
      dy--;
      dis++;
    }
    else {
      x = parent(x, dx);
      dx--;
      y = parent(y, dy);
      dy--;
      dis += 2;
    }
  }
  return dis;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  int q;
  cin >> q;
  memset(cache, -1, sizeof(cache));
  while (q--) {
    uint64_t x, y;
    cin >> x >> y;
    cout << calc_dis(x, y) << "\n";
  }
}
