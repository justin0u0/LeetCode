/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/score-of-a-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int scoreOfString(const string& s) {
    int score = 0;
    for (int i = 1; i < s.length(); ++i) {
      score += abs(s[i] - s[i - 1]);
    }
    return score;
  }
};
