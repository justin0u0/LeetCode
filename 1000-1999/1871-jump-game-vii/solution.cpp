/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/jump-game-vii/
 * Runtime: 39ms (7.55%)
 */

class Solution {
public:
  bool canReach(const string& s, const int minJump, const int maxJump) {
    const int n = s.length();

    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + s[i] - '0';
    }

    vector<bool> dp(n, false);
    dp[0] = true;
    vector<int> dsum(n + 1, 1);
    dsum[0] = 0;

    for (int i = minJump; i < n; ++i) {
      int r = i - minJump;
      int l = max(i - maxJump, 0);
      if (sum[r + 1] - sum[l] < r - l + 1) {
        dp[i] = s[i] != '1' && (dsum[r + 1] != dsum[l]);
      }
      dsum[i + 1] = dsum[i] + dp[i];
    }
    return dp[n - 1];
  }
};
