/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minAddToMakeValid(const string& s) {
    int l = 0;
    int moves = 0;
    for (char c : s) {
      if (c == '(') {
        ++l;
      } else if (l != 0) {
        --l;
      } else {
        ++moves;
      }
    }
    return moves + l;
  }
};
