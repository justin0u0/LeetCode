/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool areSimilar(const vector<vector<int>>& mat, int k) {
    const int m = mat.size();
    const int n = mat[0].size();

    k %= n;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i & 1) && mat[i][j] != mat[i][(j - k + n) % n]) {
          return false;
        }
        if (!(i & 1) && mat[i][j] != mat[i][(j + k) % n]) {
          return false;
        }
      }
    }

    return true;
  }
};
