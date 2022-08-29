/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-islands/
 * Runtime: 42ms
 */

class Solution {
private:
  int n;
  int m;

  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') {
      return;
    }

    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++answer;
        }
      }
    }
    return answer;
  }
};
