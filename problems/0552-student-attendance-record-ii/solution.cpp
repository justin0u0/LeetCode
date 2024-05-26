/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/student-attendance-record-ii/
 * Runtime: 20ms (93.17%)
 */

class Solution {
public:
  int checkRecord(int n) {
    // dp[i][j][k]: number of records at the ith day, with j absent days, and
    //  k consecutive late days.
    //
    //  - A: dp[i][j][0] += dp[i - 1][j - 1][k], ∀j,k
    //  - P: dp[i][j][0] += dp[i - 1][j][k], ∀j,k
    //  - L: dp[i][j][k] += dp[i - 1][j][k - 1], ∀j,k
    const unsigned int mod = 1e9 + 7;

    unsigned int pre[2][3] = {0};
    unsigned int cur[2][3] = {0};
    pre[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      cur[0][0] = (pre[0][0] + pre[0][1] + pre[0][2]) % mod;
      cur[0][1] = pre[0][0];
      cur[0][2] = pre[0][1];
      cur[1][0] = (cur[0][0] + pre[1][0] + pre[1][1] + pre[1][2]) % mod;
      cur[1][1] = pre[1][0];
      cur[1][2] = pre[1][1];
      swap(pre, cur);
    }

    return ((pre[0][0] + pre[0][1] + pre[0][2]) % mod +
      (pre[1][0] + pre[1][1] + pre[1][2]) % mod) % mod;
  }
};
