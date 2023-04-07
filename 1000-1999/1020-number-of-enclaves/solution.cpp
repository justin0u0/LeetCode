/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-enclaves/
 * Runtime: 68ms (91.94%)
 */

class Solution {
private:
  int n, m;

  bool dfs(vector<vector<int>>& grid, int i, int j, int& sum) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
      return false;
    }
    if (grid[i][j] == 0) {
      return true;
    }

    grid[i][j] = 0;
    ++sum;

    bool ok = true;
    ok &= dfs(grid, i + 1, j, sum);
    ok &= dfs(grid, i, j + 1, sum);
    ok &= dfs(grid, i - 1, j, sum);
    ok &= dfs(grid, i, j - 1, sum);
    return ok;
  }
public:
  int numEnclaves(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          int sum = 0;
          if (dfs(grid, i, j, sum)) {
            answer += sum;
          }
        }
      }
    }
    return answer;
  }
};
