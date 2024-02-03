/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-array-for-maximum-sum/
 * Runtime: 4ms (96.87%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int dp[501];
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    const int n = arr.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      int& d = dp[i];
      int maxVal = 0;
      for (int j = i - 1; j >= max(0, i - k); --j) {
        maxVal = max(maxVal, arr[j]);
        d = max(d, dp[j] + maxVal * (i - j));
      }
    }
    return dp[n];
  }
};

// dp(i): maximum sum after partitioning of arr[0:i)
//
// dp(i) = max(dp(j) + max(arr(i+1:j]) * (i - j)) where j < i && i - j < k

