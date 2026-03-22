/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    const int n = mat.size();

    bitset<4> equal("1111");

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] != target[i][j]) {
          equal[0] = false;
        }
        if (mat[i][j] != target[j][n - i - 1]) {
          equal[1] = false;
        }
        if (mat[i][j] != target[n - i - 1][n - j - 1]) {
          equal[2] = false;
        }
        if (mat[i][j] != target[n - j - 1][i]) {
          equal[3] = false;
        }
      }
    }

    return equal.any();
  }
};
