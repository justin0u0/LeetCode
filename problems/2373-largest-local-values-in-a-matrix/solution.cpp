/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-local-values-in-a-matrix/
 * Runtime: 6ms (92.14%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> largestLocal(const vector<vector<int>>& grid) {
    const int n = grid.size();
    vector<vector<int>> local(n - 2, vector<int>(n - 2, 0));
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        int& val = local[i - 1][j - 1];
        for (int x = -1; x < 2; ++x) {
          for (int y = -1; y < 2; ++y) {
            val = max(val, grid[i + x][j + y]);
          }
        }
      }
    }
    return local;
  }
};
