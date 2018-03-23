#include <iostream>

using namespace std;

const int64_t INF = 10000000;

int64_t n;
int64_t numbers[100001];

int64_t get_max(int s, int e) {
  if (s == e)
    return numbers[s];

  int mid = (s + e) / 2;
  int64_t left = get_max(s, mid);
  int64_t right = get_max(mid + 1, e);
  int64_t sum = 0;
  int64_t min_val = INF;
  int64_t merge = 0;

  int front = mid;
  int rear = mid + 1;

  while (front != s - 1 || rear != e + 1) {
    int index = 0;

    if (front == s - 1) {
      index = rear;
      rear++;
    }
    else if (rear == e + 1) {
      index = front;
      front--;
    }
    else {
      if (numbers[front] > numbers[rear]) {
        index = front;
        front--;
      }
      else {
        index = rear;
        rear++;
      }
    }

//    cout << "front: " << front << ", rear: " << rear << ", index: " << index << "\n";
    min_val = min(min_val, numbers[index]);
    sum += numbers[index];
    merge = max(merge, min_val * sum);
  }

//  cout << "s: " << s << ", e: " << e << ", merge: " << merge <<
//    ", left: " << left << ", right:" << right << "\n";

  return max(left, max(right, merge));
}

int main() {
  cin >> n;
  for (int64_t i = 0; i < n; i++)
    cin >> numbers[i];
  cout << get_max(0, n - 1) << "\n";
}
