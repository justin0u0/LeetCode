/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-falling-path-sum-ii/
 * Runtime: 16ms (99.03%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    int m1 = 0;
    int mi = -1;
    int m2 = 0;
    for (int i = 0; i < n; ++i) {
      int next1 = INT_MAX;
      int nexti = 0;
      int next2 = INT_MAX;
      for (int j = 0; j < m; ++j) {
        int& val = grid[i][j];
        if (j == mi) {
          val += m2;
        } else {
          val += m1;
        }
        if (val < next1) {
          next2 = next1;
          next1 = val;
          nexti = j;
        } else if (val < next2) {
          next2 = val;
        }
      }
      m1 = next1;
      mi = nexti;
      m2 = next2;
    }
    return *min_element(grid.back().begin(), grid.back().end());
  }
};
