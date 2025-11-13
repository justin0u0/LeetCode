/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
 * Runtime: 2ms (86.23%)
 */

class Solution {
public:
  int maxOperations(const string& s) {
    int ops = 0;
    int cnt = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == '1') {
        ++cnt;
      }
      if (s[i] == '1' && s[i + 1] == '0') {
        ops += cnt;
      }
    }
    return ops;
  }
};
