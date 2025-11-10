/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
 * Runtime: 32ms (75.28%)
 */

class Solution {
public:
  int minOperations(const vector<int>& nums) {
    stack<int> stk;
    int ops = 0;
    for (int num : nums) {
      while (!stk.empty() && stk.top() >= num) {
        if (stk.top() > num) {
          ++ops;
        }
        stk.pop();
      }
      if (num != 0) {
        stk.push(num);
      }
    }
    return ops += stk.size();
  }
}
