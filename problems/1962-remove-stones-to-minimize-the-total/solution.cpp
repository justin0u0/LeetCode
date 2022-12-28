/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
 * Runtime: 540ms (93.10%)
 */

class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    int sum = 0;
    priority_queue<int> q;
    for (const int& p : piles) {
      q.push(p);
      sum += p;
    }

    for (int i = 0; i < k; ++i) {
      int x = q.top();
      int y = x >> 1;
      q.pop();
      q.push(x - y);
      sum -= y;
    }
    return sum;
  }
};
