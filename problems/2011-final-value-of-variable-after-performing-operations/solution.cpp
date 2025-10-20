/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int finalValueAfterOperations(const vector<string>& operations) {
    int val = 0;
    for (const auto& op : operations) {
      if (op[1] == '+') {
        ++val;
      } else {
        --val;
      }
    }
    return val;
  }
};
