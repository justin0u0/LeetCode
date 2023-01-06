/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-ice-cream-bars/
 * Runtime: 189ms (93.96%)
 */

class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int n = costs.size();
    for (int i = 0; i < n; ++i) {
      if (coins < costs[i]) {
        return i;
      }
      coins -= costs[i];
    }

    return n;
  }
};
