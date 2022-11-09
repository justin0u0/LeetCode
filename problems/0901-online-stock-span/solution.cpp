/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/online-stock-span/
 * Runtime: 240ms (88.86%)
 */

class StockSpanner {
private:
  stack<pair<int, int>> stk;
public:
  StockSpanner() {}

  int next(int price) {
    int count = 1;
    while (!stk.empty() && stk.top().first <= price) {
      count += stk.top().second;
      stk.pop();
    }

    stk.push(pair{price, count});
    return count;
  }
};
