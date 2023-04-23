/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/restore-the-array/
 * Runtime: 34ms (96.51%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

public:
  int numberOfArrays(const string& s, int k) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0') {
        continue;
      }

      long long sum = 0;
      for (int j = i; j < n; ++j) {
        sum = sum * 10 + s[j] - '0';
        if (sum > k) {
          break;
        }
        dp[i] = (dp[i] + dp[j + 1]) % mod;
      }
    }

    return dp[0];
  }
}
