/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/painting-the-walls/
 * Runtime: 38ms (99.69%)
 */

class Solution {
private:
  int dp[501];
public:
  int paintWalls(const vector<int>& cost, const vector<int>& time) {
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;

    const int n = cost.size();
    for (int i = 0; i < n; ++i) {
      const int c = cost[i];
      const int t = time[i];
      for (int j = n; j > 0; --j) {
        dp[j] = min(dp[j], dp[max(j - t - 1, 0)] + c);
      }
    }
    return dp[n];
  }
};

// dp(j) is the minimum cost needed to paint j walls
//  = min{dp(j - time[i] - 1) + cost[i]}
//
// If the ith wall is paint by the paid painter, it paints 1
// wall and at the same time time[i] walls can be painted by
// the free painter.
