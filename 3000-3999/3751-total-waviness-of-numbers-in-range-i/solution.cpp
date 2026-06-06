/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
 * Runtime: 47ms (59.23%)
 */

class Solution {
public:
  int totalWaviness(int num1, int num2) {
    int total = 0;
    for (int i = num1; i <= num2; ++i) {
      string s = to_string(i);
      for (int j = 1; j + 1 < s.length(); ++j) {
        if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
          ++total;
        } else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
          ++total;
        }
      }
    }
    return total;
  }
};
