/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    if (cost1 + cost2 <= costBoth) {
      return (long long)cost1 * need1 + (long long)cost2 * need2;
    }
    long long cost = (long long)costBoth * min(need1, need2);
    if (need1 < need2) {
      return cost + (long long)min(cost2, costBoth) * (need2 - need1);
    }
    return cost + (long long)min(cost1, costBoth) * (need1 - need2);
  }
};
