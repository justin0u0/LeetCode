/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
 * Runtime: 16ms (72.67%)
 */

class Solution {
public:
  int maximumJumps(const vector<int>& nums, const int target) {
    const int n = nums.size();
    vector<int> dp(n, 0xc0c0c0c0);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (abs(nums[j] - nums[i]) <= target) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return max(dp.back(), -1);
  }
};
