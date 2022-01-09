/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/cherry-pickup-ii/
 * Runtime: 24ms
 * Time Complexity: O(NM^2)
 * Space Complexity: O(M^2)
 * Description:
 *  DP with scrolling array optimization.
 *
 *  dp(k, i, j) is the maximum cherry collection when robot #1 is at (k, i)
 *  and robot #2 is at (k, j).
 *
 *  So dp(k, i, j) = max{dp(k - 1, prei, prej)} when prei ∈ [i - 1, i + 1]
 *  and prej ∈ [j - 1, j + 1].
 *
 *  Since we only need dp(k - 1, ?, ?) for calculation, we can reuse the first
 *  dimension of the array and reduce the space complexity from O(NM^2) to
 *  O(2*N^2) which equals to O(N^2).
 */

class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    int dp[2][71][71];
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

    for (int k = 1; k < n; ++k) {
      int cur = k & 1;
      int pre = cur ^ 1;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
          int& best = dp[cur][i][j];
          for (int di = -1; di < 2; ++di) {
            for (int dj = -1; dj < 2; ++dj) {
              int prei = i + di;
              int prej = j + dj;
              if (prei < 0 || prej < 0 || prei >= m || prej >= m) continue;

              best = max(best, dp[pre][prei][prej]);
            }
          }
          
          if (i == j) {
            best += grid[k][i];
          } else {
            best += grid[k][i] + grid[k][j];
          }
        }
      }
    }

    int answer = 0;
    int cur = (n - 1) & 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        answer = max(answer, dp[cur][i][j]);
      }
    }

    return answer;
  }
};
