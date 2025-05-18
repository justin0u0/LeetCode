/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
 * Runtime: 71ms (51.72%)
 */

class Solution {
private:
  const static int mod = 1e9 + 7;
public:
  int colorTheGrid(const int m, const int n) {
    // dp(i, j) is the number of ways to paint until the ith column,
    // with the last column colored as j, where j is base-4 number
    // and each digit represent a color (0 is invalid color).
    vector<vector<int>> dp(n, vector<int>(1 << (m << 1), 0));

    vector<int> colors;
    for (int i = 0; i < (1 << (m << 1)); ++i) {
      bool ok = true;
      for (int mask = 3; mask < (1 << (m << 1)); mask <<= 2) {
        if ((i & mask) == 0) {
          ok = false;
        }
      }
      for (int mask = 3; mask < (1 << ((m << 1) - 1)); mask <<= 2) {
        if (((i & mask) << 2) == (i & (mask << 2))) {
          ok = false;
        }
      }
      if (ok) {
        colors.emplace_back(i);
      }
    }

    for (int i : colors) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
      for (int j : colors) {
        for (int k : colors) {
          bool ok = true;
          for (int mask = 3; mask < (1 << (m << 1)); mask <<= 2) {
            if ((j & mask) == (k & mask)) {
              ok = false;
            }
          }
          if (ok) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= mod;
          }
        }
      }
    }

    int total = 0;
    for (int i : colors) {
      total = (total + dp[n - 1][i]) % mod;
    }
    return total;
  }
};
