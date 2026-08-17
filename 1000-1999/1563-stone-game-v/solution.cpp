/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-v/
 * Runtime: 731ms (26.83%)
 */

class Solution {
public:
  int stoneGameV(const vector<int>& stones) {
    const int n = stones.size();

    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + stones[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    auto dfs = [&](this auto&& self, int l, int r) {
      if (r - l < 1) {
        return 0;
      }
      if (dp[l][r] != -1) {
        return dp[l][r];
      }

      int left = 0;
      int right = sum[r + 1] - sum[l];
      int& best = dp[l][r];
      best = 0;
      for (int i = l; i < r; ++i) {
        left += stones[i];
        right -= stones[i];

        if (left < right) {
          best = max(best, self(l, i) + left);
        } else if (left > right) {
          best = max(best, self(i + 1, r) + right);
        } else {
          best = max({best, self(l, i) + left, self(i + 1, r) + right});
        }
      }

      return best;
    };
    
    return dfs(0, n - 1);
  }
};
