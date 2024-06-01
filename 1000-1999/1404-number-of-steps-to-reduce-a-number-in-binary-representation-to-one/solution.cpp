/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numSteps(const string& s) {
    bool carry = false;
    int steps = s.length() - 1;
    for (int i = s.length() - 1; i > 0; --i) {
      bool f = (s[i] == '1');
      if (carry ^ f) {
        ++steps;
      }
      carry |= f;
    }
    return steps + carry;
  }
};
