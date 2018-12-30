#include <iostream>
#include <cstring>

using namespace std;

int nWords;
string words[10];
bool hasChar['Z' - 'A' + 1];
bool assignedNumber[10];
int assignChar['Z' - 'A' + 1];
int maxSum;

void dfs(int charPos) {
  if (charPos > 'Z' - 'A' + 1) {
    // Base case

//    cout << "assignments:\n";
//    for (int i = 0; i < 'Z' - 'A' + 1; i++) {
//      if (hasChar[i])
//        cout << "\tchar: " << (char)(i + 'A') << " -> " << assignChar[i] << "\n";
//    }
//    cout << "\n";

    int sum = 0;
    for (int i = 0; i < nWords; i++) {
      int wordNum = 0;
      for (char s : words[i])
        wordNum = wordNum * 10 + assignChar[s - 'A'];
      sum += wordNum;
    }

//    cout << "sum is " << sum << "\n";
    if (maxSum < sum) {
//      cout << "maxSum becomes " << sum << "\n";
      maxSum = sum;
    }
//    cout << "\n";

    return;
  }

  if (hasChar[charPos]) {
    for (int i = 0; i < 10; i++) {
      if (!assignedNumber[i]) {
        assignChar[charPos] = i;
        assignedNumber[i] = true;
        dfs(charPos + 1);
        assignedNumber[i] = false;
      }
    }
  }
  else
    dfs(charPos + 1);
}

int main() {
  cin >> nWords;
  for (int i = 0; i < nWords; i++) {
    cin >> words[i];
    for (char s : words[i]) {
        hasChar[s - 'A'] = true;
    }
  }

  dfs(0);

  cout << maxSum << "\n";
}
