/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-ideal-subsequence/
 * Runtime: 17ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestIdealString(const string& s, int k) {
    int dp[26] = {0};

    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'a';
      int longest = 0;
      for (int j = max(c - k, 0); j <= min(c + k, 25); ++j) {
        longest = max(longest, dp[j] + 1);
      }
      dp[c] = longest;
    }
    return *max_element(dp, dp + 26);
  }
};
