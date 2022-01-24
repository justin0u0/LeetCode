/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/detect-capital/
 * Runtime: 3ms
 */

class Solution {
public:
  bool detectCapitalUse(string word) {
    bool allLowercase = true;
    bool allUppercase = true;
    bool onlyFirstUppercase = word[0] >= 'A' && word[0] <= 'Z';

    int n = (int)word.length();
    for (int i = 0; i < n; ++i) {
      if (word[i] >= 'A' && word[i] <= 'Z') {
        allUppercase = false;
        if (i) {
          onlyFirstUppercase = false;
        }
      } else {
        allLowercase = false;
      }
    }

    return allUppercase || allLowercase || onlyFirstUppercase;
  }
};
