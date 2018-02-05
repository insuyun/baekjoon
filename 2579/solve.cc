#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> scores;
  for (int i = 0 ; i < n; i++) {
    int score;
    cin >> score;
    scores.push_back(score);
  }

  vector<vector<int>> max_scores(n + 2);

  for (int i = 0; i < n + 2; i++)
    max_scores[i] = vector<int>(2);

  max_scores[0][0] = 0;
  max_scores[0][1] = 0;
  max_scores[1][0] = 0;
  max_scores[1][1] = 0;

  for (int i = 2; i < n + 2; i++) {
    max_scores[i][0] = max(max_scores[i - 2][0], max_scores[i - 2][1]) + scores[i - 2];
    max_scores[i][1] = max_scores[i - 1][0] + scores[i - 2];
  }

  cout << max(max_scores[n+1][0], max_scores[n+1][1]) << endl;
}
