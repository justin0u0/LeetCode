/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
 * Runtime: 237ms (94.26%)
 */

class Solution {
public:
  int minimumArea(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    int mni = n, mxi = 0;
    int mnj = m, mxj = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          mni = min(mni, i);
          mxi = max(mxi, i);
          mnj = min(mnj, j);
          mxj = max(mxj, j);
        }
      }
    }
    return (mxi - mni + 1) * (mxj - mnj + 1);
  }
};
