#include <iostream>
#include <climits>

using namespace std;

const int64_t MAX = 100001;
const int64_t INF = INT_MAX;
int64_t numbers[MAX];

int64_t get_max_height(int64_t s, int64_t e) {
  if (s == e)
    return numbers[s];

  int64_t mid = (s + e) / 2;

  int64_t height = INF;
  int64_t width = 0;
  int64_t front = mid;
  int64_t rear = mid + 1;
  int64_t square = 0;

  while (front != s - 1 || rear != e + 1) {
//    cout << front << ", rear:" << rear << ", e: " << e << "\n";
    int64_t index = 0;
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

    height = min(numbers[index], height);
    width++;
    //cout << "height: " << height << ", width: " << width << ", square: " << width*height << "\n";
    square = max(square, width * height);
  }

  //cout << "s: " << s << ", e : "<< e << ", square: " << square << "\n";
  return max(get_max_height(s, mid), max(get_max_height(mid + 1, e), square));
}

int main() {
  int64_t n;

  cin >> n;
  for (int64_t i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  cout << get_max_height(0, n - 1) << "\n";
}
