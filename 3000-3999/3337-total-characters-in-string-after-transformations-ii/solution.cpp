/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/
 * Runtime: 201ms (87.50%)
 */

class Solution {
private:
  static constexpr size_t N = 26;
  using Matrix = array<array<int, N>, N>;

  static constexpr Matrix identify = [] {
    Matrix m{};
    for (size_t i = 0; i < N; ++i) {
      m[i][i] = 1;
    }
    return m;
  }();

  const int mod = 1e9 + 7;

  Matrix pow(Matrix m, int p) {
    Matrix res = identify;
    while (p != 0) {
      if (p & 1) {
        res = mul(res, m);
      }
      m = mul(m, m);
      p >>= 1;
    }
    return res;
  }

  Matrix mul(const Matrix& a, const Matrix& b) {
    Matrix c{};
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % mod;
        }
      }
    }
    return c;
  }
public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    Matrix trans{};
    for (size_t i = 0; i < N; ++i) {
      for (int j = 1; j <= nums[i]; ++j) {
        trans[(i + j) % N][i] = 1;
      }
    }

    Matrix mat = pow(trans, t);

    int vec[N] = {};
    for (char c : s) {
      ++vec[c - 'a'];
    }

    // vec * mat
    int len = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        len = (len + (long long)vec[i] * mat[j][i]) % mod;
      }
    }

    return len;
  }
};
