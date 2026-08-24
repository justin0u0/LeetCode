/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-viii/
 * Runtime: 94ms (91.07%)
 */

class Solution {
public:
  int stoneGameVIII(vector<int>& stones) {
    // dp[i][0]: maximum score difference when stones[i:] left
    //  = max{dp[j][1] + sum(stones[0:j])}
    // dp[i][1]: minimum score difference when stones[i:] left
    //  = min{dp[i][0] + sum(stones[0:j])}

    const auto n = stones.size();

    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + stones[i];
    }

    int prev0 = 0; // dp[i + 1][0]
    int prev1 = 0; // dp[i + 1][1]
    int best0 = INT_MIN; // maximum dp[j][1] + sum[j + 1]
    int best1 = INT_MAX; // minimum dp[j][0] - sum[j + 1]

    for (int i = n - 2; i >= 0; --i) {
      best0 = max(best0, prev1 + sum[i + 2]);
      best1 = min(best1, prev0 - sum[i + 2]);
      prev0 = best0;
      prev1 = best1;
    }

    return prev0;
  }
};
