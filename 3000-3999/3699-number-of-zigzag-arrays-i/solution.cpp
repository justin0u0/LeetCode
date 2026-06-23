/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-zigzag-arrays-i/
 * Runtime: 1256ms (28.70%)
 */

class Solution {
private:
  inline static constexpr int mod = 1e9 + 7;
public:
  int zigZagArrays(const int n, const int l, const int r) {
    // dp[i][j][z]: number of ZigZag array of length i, ends with number j
    //  z=0: the next number must be increasing
    //  z=1: the next number must be decreasing
    // 
    //  = sum{dp[i - 1][k][z^1]}
    //   k > j, if z=0; otherwise k < j

    const auto N = r + 1;

    vector<vector<int>> prev(N, vector<int>(2));
    for (int i = l; i <= r; ++i) {
      prev[i][0] = 1;
      prev[i][1] = 1;
    }
    vector<vector<int>> curr(N, vector<int>(2));

    vector<vector<int>> sum(N + 1, vector<int>(2, 0));
    for (int i = l; i <= r; ++i) {
      sum[i][0] = sum[i - 1][0] + prev[i][0];
      sum[i][1] = sum[i - 1][1] + prev[i][1];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = l; j <= r; ++j) {
        // curr[j][0] = prev[j + 1][1] + .. + prev[r][1]
        curr[j][0] = (sum[r][1] - sum[j][1] + mod) % mod;
        // curr[j][1] = prev[j - 1][0] + .. + prev[l][0]
        curr[j][1] = (sum[j - 1][0] - sum[l - 1][0] + mod) % mod;
      }
      swap(prev, curr);
      for (int i = l; i <= r; ++i) {
        sum[i][0] = (sum[i - 1][0] + prev[i][0]) % mod;
        sum[i][1] = (sum[i - 1][1] + prev[i][1]) % mod;
      }
    }

    return ranges::fold_left(prev, 0, [](int acc, const auto& vec) {
      return ((acc + vec[0]) % mod + vec[1]) % mod;
    });
  }
};
