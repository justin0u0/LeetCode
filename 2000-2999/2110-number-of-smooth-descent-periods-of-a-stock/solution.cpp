/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
 * Runtime: 1ms (49.44%)
 */

class Solution {
public:
  long long getDescentPeriods(const vector<int>& prices) {
    long long count = 1;
    int desc = 1;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] == prices[i - 1] - 1) {
        ++desc;
      } else {
        desc = 1;
      }
      count += desc;
    }
    return count;
  }
};
