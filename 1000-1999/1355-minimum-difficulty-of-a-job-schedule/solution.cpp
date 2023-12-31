/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
 * Runtime: 23ms (84.24%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int INF = 0x3f3f3f3f;
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) {
      return -1;
    }

    vector<vector<int>> dp(d + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= d; ++i) {
      for (int j = i; j <= n; ++j) {
        int cost = 0;
        int& best = dp[i][j];
        for (int k = j - 1; k >= 0; --k) {
          cost = max(cost, jobDifficulty[k]);
          best = min(best, dp[i - 1][k] + cost);
        }
      }
    }

    return dp[d][n];
  }
};

// dp(i, j) = min(dp(i - 1, k) + max{k + 1, j}) where k = [0, j-1]
