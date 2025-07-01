/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-original-typed-string-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int possibleStringCount(const string& word) {
    int pos = 1;
    for (int i = 1; i < word.size(); ++i) {
      if (word[i] == word[i - 1]) {
        ++pos;
      }
    }
    return pos;
  }
};
