/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-x-value-of-array-i/
 * Runtime: 167ms (41.07%)
 */

class Solution {
public:
  vector<long long> resultArray(const vector<int>& nums, const int k) {
    const int n = nums.size();

    // dp[i][j]: number of subarrays nums[?:i] whose product remainder divided by k is j
    //  dp[i][j] += dp[i - 1][j'] where j = j' * nums[i] % k
    vector<vector<int>> dp(n, vector<int>(k, 0));
    dp[0][nums[0] % k] = 1;

    for (int i = 1; i < n; ++i) {
      dp[i][nums[i] % k] = 1;
      for (int j = 0; j < k; ++j) {
        dp[i][(long long)j * nums[i] % k] += dp[i - 1][j];
      }
    }

    vector<long long> ans(k, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        ans[j] += dp[i][j];
      }
    }
    return ans;
  }
};
