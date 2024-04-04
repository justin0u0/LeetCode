/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxDepth(const string& s) {
    int d = 0;
    int answer = 0;
    for (char c : s) {
      if (c == '(') {
        ++d;
        answer = max(answer, d);
      } else if (c == ')') {
        --d;
      }
    }
    return answer;
  }
};
