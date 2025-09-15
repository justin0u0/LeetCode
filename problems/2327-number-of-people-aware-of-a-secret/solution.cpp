/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 * Runtime: 11ms (28.13%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // dp[i]: number of people aware of secret at the ith day
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
      for (int j = max(i - forget + 1, 0); j <= i - delay; ++j) {
        dp[i] = (dp[i] + dp[j]) % mod;
      }
    }
    int res = 0;
    for (int i = n - forget; i < n; ++i) {
      res = (res + dp[i]) % mod;
    }
    return res;
  }
};
