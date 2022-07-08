/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/paint-house-iii/
 * Runtime: 65ms
 * Time Complexity: O(M*M*N*N)
 * Space Complexity: O(M*M*N)
 * Description:
 * 	Let dp(i, j, c) be the minimum cost of houses[1, i] where already have j neighbors and end
 * 		with color c.
 *
 * 	dp(i, j, c) = min{
 * 		dp(i - 1, j - 1, c2) + cost(i, c), for all c2 != c, 1 <= c2 <= n
 * 		dp(i - 1, j, c) + cost(i, c)
 * 	} where houses[i] == 0 || houses[i] == c
 * 	
 * 	Note that cost(i, c) should be 0 if houses[i] is already painted.
 */

class Solution {
#define MAXN 21
#define MAXM 101
#define INF 0x3f3f3f3f
private:
  int dp[MAXM][MAXM][MAXN];
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    memset(dp, INF, sizeof dp);
    for (int c = 1; c <= n; ++c) {
      dp[0][0][c] = 0;
      dp[0][1][c] = 0;
    }

    int h = houses.size();
    for (int i = 1; i <= h; ++i) {
      int maxJ = min(i, target);
      for (int j = 1; j <= maxJ; ++j) {
        for (int c = 1; c <= n; ++c) {
          if (houses[i - 1] == 0 || houses[i - 1] == c) {
            int nowCost = (houses[i - 1] == 0) ? cost[i - 1][c - 1] : 0;
            for (int c2 = 1; c2 <= n; ++c2) {
              if (c != c2) {
                dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j - 1][c2] + nowCost);
              } else {
                dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c] + nowCost);
              }
            }
          }
        }
      }
    }

    int answer = INF;
    for (int c = 1; c <= n; ++c) {
      answer = min(answer, dp[h][target][c]);
    }

    return (answer == INF) ? -1 : answer;
  }
};
