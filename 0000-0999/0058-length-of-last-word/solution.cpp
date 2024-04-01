/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/length-of-last-word/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int lengthOfLastWord(const string& s) {
    auto it = s.crbegin();
    while (*it == ' ') {
      ++it;
    }
    int len = 0;
    for (; it != s.crend() && *it != ' '; ++it) {
      ++len;
    }
    return len;
  }
};
