#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int heights[9];

bool brute(vector<int>& v, int sum, int start, int skip) {
  if (skip > 2)
    return false;

  if (start == 9) {
    if (skip == 2 && sum == 100)
      return true;
    else
      return false;
  }

  // skip this index
  if (brute(v, sum, start + 1, skip + 1))
    return true;

  v.push_back(heights[start]);
  sum += heights[start];
  if (brute(v, sum, start + 1, skip))
    return true;
  v.pop_back();
  return false;
}

int main() {
  for (int i = 0; i < 9; i++)
    cin >> heights[i];

  vector<int> v;
  assert(brute(v, 0, 0, 0));

  sort(v.begin(), v.end());

  for (int e : v)
    cout << e << "\n";
}
