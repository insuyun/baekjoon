#include <vector>
#include <iostream>

using namespace std;

#define MAX 400000000

int n, k;
int numbers[8];
int answer;
int cache[8][10000000];

int getAnswer() {
  int h = 0;
  for (int i = 0; i < n - 1; i++) {
    h = 10 * h + (i + 1);
  }
  return h;
}

int getHash() {
  int h = 0;
  for (int i = 0; i < n - 1; i++) {
    h =  10 * h + numbers[i];
  }

  return h;
}

void swap(int i) {
  for (int j = i; j < i + k / 2; j++) {
    int temp = numbers[j];
    numbers[j] = numbers[i + k - j - 1];
    numbers[i + k - j - 1] = temp;
  }
}

short dfs(int c) {
  int h = getHash();

  // cout << h << ", " << answer << "\n";
  if (h == answer)
    return 0;

  if (c > k)
    return MAX;

  short &ret = cache[c][h];
  if (ret != 0)
    return ret;

  ret = MAX;

  for (int i = 0; i <= n - k; i++) {
    swap(i);
    ret = min(ret, 1 + dfs(c + 1));
    swap(i);
  }

  return ret;
}

int main() {
  // memset(cache, -1, sizeof(cache));
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  answer = getAnswer();
  cout << dfs(0) << "\n";
}
