/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/circular-sentence/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isCircularSentence(const string& s) {
    for (int i = 1; i < s.size() - 1; ++i) {
      if (s[i] == ' ' && s[i - 1] != s[i + 1]) {
        return false;
      }
    }
    return s[0] == s.back();
  }
};
