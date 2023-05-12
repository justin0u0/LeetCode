/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/solving-questions-with-brainpower/
 * Runtime: 341ms (97.88%)
 */

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
private:
  long long dp[100010];
public:
  long long mostPoints(vector<vector<int>>& questions) {
    reverse(questions.begin(), questions.end());
    int n = questions.size();

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int j = max(0, i - questions[i - 1][1] - 1);
      dp[i] = max(dp[i - 1], dp[j] + questions[i - 1][0]);
    }
    return dp[n];
  }
};
