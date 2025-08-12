/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
 * Runtime: 1665ms (5.01%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  inline int pow(int a, int p) {
    int res = 1;
    while (p--) {
      res = res * a;
    }
    return res;
  }
public:
  int numberOfWays(int n, int x) {
    // dp[i][j]: number of ways to express i, and the last number is j
    //  = sum{dp[i - j ^ x][k]}, for all k < j

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; pow(j, x) <= i; ++j) {
        for (int k = 0; k < j; ++k) {
          dp[i][j] = (dp[i][j] + dp[i - pow(j, x)][k]) % mod;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
      sum = (sum + dp[n][i]) % mod;
    }
    return sum;
  }
};
