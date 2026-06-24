/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-zigzag-arrays-ii/
 * Runtime: 2381ms (6.98%)
 */

class Solution {
public:
  int zigZagArrays(const int n, const int l, const int r) {
    using Mat = vector<vector<int>>;

    const auto m = r - l + 1; // [l, r] equals to [0, r-l+1]
    const auto M = m << 1;
    const int mod = 1e9 + 7;

    // Turn https://leetcode.com/problems/number-of-zigzag-arrays-i into matrix
    // multiplication.
    //
    // IV (initial vector), size=M*1, unit matrix
    //
    // mat: DP transition:
    //  -  first m elements: curr[i][0]
    //      = sum{prev[j][1]}, j > i
    //  - second m elements: curr[i][1]
    //      = sum{prev[j][0]}, j < i
    //
    // result = mat^(n-1) * IV ~ equivalent to sum of mat^(n-1)

    auto mul = [&](const Mat& lhs, const Mat& rhs) {
      Mat res(M, vector<int>(M, 0));
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
          for (int k = 0; k < M; ++k) {
            res[i][j] = (res[i][j] + (long long)lhs[i][k] * rhs[k][j] % mod) % mod;
          }
        }
      }
      return res;
    };

    auto pow = [&](Mat& a, int p) {
      Mat res(M, vector<int>(M, 0));
      for (int i = 0; i < M; ++i) {
        res[i][i] = 1;
      }
      while (p > 0) {
        if (p & 1) {
          res = mul(res, a);
        }
        a = mul(a, a);
        p >>= 1;
      }
      return res;
    };

    Mat mat(M, vector<int>(M, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        // first m elements
        if (i < m && j >= m && j - m > i) {
          mat[i][j] = 1;
        }
        // second m elements
        if (i >= m && j < m && j < i - m) {
          mat[i][j] = 1;
        }
      }
    }

    const auto res = pow(mat, n - 1);
    return ranges::fold_left(res, 0, [](int acc, const auto& row) {
      return (acc + ranges::fold_left(row, 0, [](int acc2, int cell) {
        return (acc2 + cell) % mod;
      })) % mod;
    });
  }
};
