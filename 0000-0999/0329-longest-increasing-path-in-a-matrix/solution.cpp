/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * Runtime: 52ms
 */

class Solution {
private:
  int n;
  int m;

  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (dp[x][y] != 0) {
      return dp[x][y];
    }

    dp[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m || matrix[nx][ny] <= matrix[x][y]) {
        continue;
      }

      dp[x][y] = max(dp[x][y], dfs(nx, ny, matrix, dp) + 1);
    }

    return dp[x][y];
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = (int)matrix.size();
    m = (int)matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j] == 0) {
          answer = max(answer, dfs(i, j, matrix, dp));
        }
      }
    }

    return answer;
  }
};
