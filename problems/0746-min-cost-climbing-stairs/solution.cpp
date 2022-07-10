/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/min-cost-climbing-stairs/
 * Runtime: 7ms
 */

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = (int)cost.size();
    for (int i = 2; i < n; ++i) {
      cost[i] += min(cost[i - 1], cost[i - 2]);
    }

    return min(cost[n - 1], cost[n - 2]);
  }
};
