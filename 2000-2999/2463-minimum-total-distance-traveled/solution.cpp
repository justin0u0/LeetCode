/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-total-distance-traveled/
 * Runtime: 12ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  // Assume that both robot and factory array are starting with index 1.
  //
  // Let dp[i][j] be the minimum total distance to repair robot[1:j] with factory[1:i].
  //  dp[i][j] = min{dp[i - 1][k - 1] + total distance to repair robot[k,j] with factory[i]},
  //    where k - j + 1 >= factory[i].limit
  //
  // Also it is possible that factory[i] repair nothing, which is
  //  dp[i][j] = dp[i - 1][j]
  long long dp[101][101];
public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    const int n = factory.size();
    const int m = robot.size();

    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 0;
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = 1e15;
      }
    }

    for (int i = 1; i <= n; ++i) {
      const auto& f = factory[i - 1];
      for (int j = 1; j <= m; ++j) {
        long long& d = dp[i][j];
        d = dp[i - 1][j];

        long long sum = 0;
        for (int k = j; k > max(j - f[1], 0); --k) {
          sum += abs(robot[k - 1] - f[0]);
          d = min(d, dp[i - 1][k - 1] + sum);
        }
      }
    }
    return dp[n][m];
  }
};
