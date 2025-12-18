/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/
 * Runtime: 4ms (92.95%)
 */

class Solution {
public:
  long long maxProfit(const vector<int>& prices, const vector<int>& strategy, const int k) {
    const int n = prices.size();
    long long maxp = 0;
    for (int i = 0; i < n; ++i) {
      maxp += prices[i] * strategy[i];
    }

    long long sum = maxp;
    for (int i = 0; i < k / 2; ++i) {
      sum -= prices[i] * strategy[i];
    }
    for (int i = k / 2; i < k; ++i) {
      sum += prices[i] * (1 - strategy[i]);
    }

    maxp = max(maxp, sum);
    for (int i = k; i < n; ++i) {
      sum += prices[i - k] * strategy[i - k];
      sum -= prices[i - k / 2];
      sum += prices[i] * (1 - strategy[i]);
      maxp = max(maxp, sum);
    }
    return maxp;
  }
};
