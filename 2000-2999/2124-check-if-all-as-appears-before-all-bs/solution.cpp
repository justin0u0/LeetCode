/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool checkString(const string& s) {
    bool b = false;
    for (char c : s) {
      if (c == 'b') {
        b = true;
      }
      if (b && c == 'a') {
        return false;
      }
    }
    return true;
  }
};
