/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * Runtime: 123ms (95.55%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n + 1, 1);
    vector<int> sum(n + 1, 1);
    int maxDp = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int& d = dp[i];
      for (int j = 1; j < i; ++j) {
        if (nums[i - 1] > nums[j - 1]) {
          if (d < dp[j] + 1) {
            d = dp[j] + 1;
            sum[i] = sum[j];
          } else if (d == dp[j] + 1) {
            sum[i] += sum[j];
          }
        }
      }
      maxDp = max(maxDp, d);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
      if (dp[i] == maxDp) {
        answer += sum[i];
      }
    }
    return answer;
  }
};
