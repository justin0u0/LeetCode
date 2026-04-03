/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-walls-destroyed-by-robots/
 * Runtime: 342ms (9.33%)
 */

class Solution {
private:
  int dp[100002][2];
public:
  int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    const int n = robots.size();
    const int m = walls.size();

    ranges::sort(views::zip(robots, distance));
    ranges::sort(walls);

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // dp[i][0]: max walls using first i robots, with the last one firing left
    // dp[i][1]: max walls using first i robots, with the last one firing right

    auto countWalls = [&](int l, int r) {
      if (l > r) {
        return 0;
      }

      int upper = ranges::upper_bound(walls, r) - walls.begin();
      int lower = ranges::lower_bound(walls, l) - walls.begin();
      return upper - lower;
    };

    for (int i = 0; i < n; ++i) {
      int left = robots[i] - distance[i];
      int left2 = left;
      if (i > 0) {
        left = max(left, robots[i - 1] + 1);
        left2 = max(left2, robots[i - 1] + distance[i - 1] + 1);
      }
      dp[i + 1][0] = max(
        dp[i][0] + countWalls(left, robots[i]),
        dp[i][1] + countWalls(left2, robots[i])
      );

      int right = robots[i] + distance[i];
      if (i + 1 < n) {
        right = min(right, robots[i + 1] - 1);
      }
      dp[i + 1][1] = max(dp[i][0], dp[i][1]) + countWalls(robots[i], right);
    }

    return max(dp[n][0], dp[n][1]);
  }
};
