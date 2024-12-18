/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> finalPrices(const vector<int>& prices) {
    const int n = prices.size();

    vector<int> res(n);

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && prices[i] <= prices[stk.top()]) {
        res[stk.top()] = prices[stk.top()] - prices[i];
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      res[stk.top()] = prices[stk.top()];
      stk.pop();
    }
    return res;
  }
};
