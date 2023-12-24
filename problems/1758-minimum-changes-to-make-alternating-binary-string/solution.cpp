/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minOperations(const string& s) {
    int d1 = 0;
    int d2 = 0;
    for (char c : s) {
      if (c == '0') {
        ++d1;
      } else {
        ++d2;
      }
      swap(d1, d2);
    }
    return min(d1, d2);
  }
};
