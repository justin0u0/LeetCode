/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
 * Runtime: 44ms (96.88%)
 */

class Solution {
private:
  int dp[105][105];
public:
  int minCost(int n, vector<int>& cuts) {
    cuts.emplace_back(0);
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());

    int m = cuts.size();
    memset(dp, 0x3f3f3f3f, sizeof(dp));

    for (int i = m - 1; i >= 0; --i) {
      dp[i][i] = 0;
      dp[i][i + 1] = 0;
      for (int j = i + 2; j < m; ++j) {
        int& d = dp[i][j];
        for (int k = i + 1; k < j; ++k) {
          d = min(d, dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
        }
      }
    }

    return dp[0][m - 1];
  }
};
