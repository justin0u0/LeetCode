/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-servers-that-communicate/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countServers(const vector<vector<int>>& grid) {
    int rows[251] = {0};
    int cols[251] = {0};

    const int n = grid.size();
    const int m = grid[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }
      }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
          ++count;
        }
      }
    }
    return count;
  }
};
