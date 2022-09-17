/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
 * Runtime: 646ms
 * Time Complexity: O(M^2)
 * Space Complexity: O(M^2)
 * Description:
 *  dp(i, j) is the maximum score when using the first i multipliers with j multipliers apply from
 *  the left.
 *
 *  dp(i, j) = max{
 *    dp(i - 1, j - 1) + multipliers[i] * nums[take from left],
 *    dp(i - 1, j) + multipliers[i] * nums[take from right]
 *  }
 */

class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -0x3f3f3f3f));

    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = dp[i - 1][0] + multipliers[i - 1] * nums[n - i];
      dp[i][i] = dp[i - 1][i - 1] + multipliers[i - 1] * nums[i - 1];
      for (int j = 1; j < i; ++j) {
        dp[i][j] = max(
          dp[i - 1][j - 1] + multipliers[i - 1] * nums[j - 1],
          dp[i - 1][j] + multipliers[i - 1] * nums[n - (i - j)]
        );
      }
    }

    int answer = -0x3f3f3f3f;
    for (int i = 0; i <= m; ++i) {
      answer = max(answer, dp[m][i]);
    }
    return answer;
  }
};
