/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
 * Runtime: 12ms (93.83%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    const int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -0x3f3f3f3f));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int mul = nums1[i] * nums2[j];
        dp[i + 1][j + 1] = max(
          max(dp[i][j + 1], dp[i + 1][j]),
          max(mul, dp[i][j] + mul)
        );
      }
    }
    return dp[n][m];
  }
};

// dp(i, j): maxDotProduct(nums1[0:i], nums2[0:j])
