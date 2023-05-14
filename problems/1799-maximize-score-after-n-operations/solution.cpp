/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-score-after-n-operations/
 * Runtime: 64ms (91.70%)
 */

class Solution {
private:
  int n;
  int m;
  int dp[1<<14];
  int g[14][14];

  int solve(int x, int i) {
    if (i == n + 1) {
      return 0;
    }
    if (dp[x] != 0) {
      return dp[x];
    }

    int d = 0;
    for (int j = 0; j < m; ++j) {
      if ((1 << j) & x) {
        continue;
      }

      int y = (1 << j) | x;
      for (int k = j + 1; k < m; ++k) {
        if ((1 << k) & y) {
          continue;
        }
        d = max(d, solve((1 << k) | y, i + 1) + i * g[j][k]);
      }
    }

    return (dp[x] = d);
  }
public:
  int maxScore(vector<int>& nums) {
    m = nums.size();
    n = m << 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        g[i][j] = gcd(nums[i], nums[j]);
      }
    }
    return solve(0, 1);
  }
};
