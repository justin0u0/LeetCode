/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumCost(vector<int>& cost) {
    const auto n = cost.size();

    ranges::sort(cost, greater<int>());
    int total = 0;
    for (int i = 0; i < n; i += 3) {
      if (i + 1 < n) {
        total += cost[i + 1];
      }
      total += cost[i];
    }
    return total;
  }
};
