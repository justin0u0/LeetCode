/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
 * Runtime: 11ms (97.05%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;
    int j = 0;
    for (int i = m - 1; i >= 0; --i) {
      while (j < n && grid[i][j] >= 0) {
        ++j;
      }
      count += n - j;
    }
    return count;
  }
};
