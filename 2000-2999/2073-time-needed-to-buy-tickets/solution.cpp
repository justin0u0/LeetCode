/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/time-needed-to-buy-tickets/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int timeRequiredToBuy(const vector<int>& tickets, const int k) {
    int t = 0;
    for (int i = 0; i <= k; ++i) {
      t += min(tickets[i], tickets[k]);
    }
    for (int i = k + 1; i < tickets.size(); ++i) {
      t += min(tickets[i], tickets[k] - 1);
    }
    return t;
  }
};
