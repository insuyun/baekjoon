#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  std::priority_queue<int> leftPq, rightPq;

  cin >> N;

  int input = 0;
  cin >> input;
  cout << input << "\n";
  leftPq.push(input);

  for (int i = 0; i < N - 1; i++) {
    // Should be balanced.
    assert(leftPq.size() - rightPq.size() <= 1);

    cin >> input;
    int leftVal = leftPq.top();
    if (input >= leftVal) {
      if (leftPq.size() == rightPq.size()) {
        if (input < -rightPq.top()) {
          leftPq.push(input);
        }
        else {
          leftPq.push(-rightPq.top());
          rightPq.pop();
          rightPq.push(-input);
        }
      }
      else {
        rightPq.push(-input);
      }
    }
    else {
      if (leftPq.size() == rightPq.size()) {
        leftPq.push(input);
      }
      else {
        rightPq.push(-leftPq.top());
        leftPq.pop();
        leftPq.push(input);
      }
    }

    cout << leftPq.top() << "\n";
  }
}
