/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/
 * Runtime: 1103ms (14.63%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  int dp[201][201][3];
public:
  int numberOfStableArrays(int zero, int one, int limit) {
    memset(dp, -1, sizeof(dp));

    function<int(int, int, int)> solve = [&](int z, int o, int end) {
      if (z == zero && o == one) {
        return 1;
      }

      int& res = dp[z][o][end];
      if (res != -1) {
        return res;
      }

      res = 0;
      for (int i = 1; i <= limit; ++i) {
        if (end != 0 && z + i <= zero) {
          res = (res + solve(z + i, o, 0)) % mod;
        }
        if (end != 1 && o + i <= one) {
          res = (res + solve(z, o + i, 1)) % mod;
        }
      }
      return res;
    };
    return solve(0, 0, 2);
  }
};
