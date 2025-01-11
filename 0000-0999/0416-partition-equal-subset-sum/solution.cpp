/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-equal-subset-sum/
 * Runtime: 39ms (94.81%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canPartition(const vector<int>& nums) {
    const int total = accumulate(nums.begin(), nums.end(), 0);
    if (total & 1) {
      return false;
    }

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    int sum = 0;
    for (int num : nums) {
      sum += num;
      for (int i = sum; i >= num; --i) {
        dp[i] = dp[i] | dp[i - num];
      }
      if (dp[total >> 1]) {
        return true;
      }
    }
    return false;
  }
};
