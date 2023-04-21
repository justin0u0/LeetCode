/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/profitable-schemes/
 * Runtime: 95ms (93.40%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  // faster way to do `target = (target + v) % mod`
  inline void add(int& target, int v) {
    target += v;
    if (target >= mod) {
      target -= mod;
    }
  }
public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    // dp(i,j,k) is the number of schemes to have at least k profits
    // in the first ith crimes,with j crimes commited.
    //  dp(i,j,k+profit[i]) = dp(i-1,j-group[i],k) + dp(i-1,j,k+profit[i])
    //
    // We reuse the DP array to a 2D-array with j loop reversely:
    //  dp(j,k+profit[i]) += dp(j-group[i],k)
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
    dp[0][0] = 1;

    int m = group.size();
    for (int i = 0; i < m; ++i) {
      int p = profit[i];
      int g = group[i];
      for (int j = n; j >= group[i]; --j) {
        for (int k = 0; k <= minProfit; ++k) {
          add(dp[j][min(k + p, minProfit)], dp[j - g][k]);
        }
      }
    }

    int sum = 0;
    for (int j = 0; j <= n; ++j) {
      add(sum, dp[j][minProfit]);
    }
    return sum;
  }
};


