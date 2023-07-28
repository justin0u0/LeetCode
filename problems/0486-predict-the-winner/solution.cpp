/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/predict-the-winner/
 * Runtime: 0ms (100.00%)
 */

class Solution {
#define INF 0x3f3f3f3f
public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -INF));
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = nums[i];
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    
    return dp[0][n - 1] >= 0;
  }
};
