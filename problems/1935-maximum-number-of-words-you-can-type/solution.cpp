/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int canBeTypedWords(const string& text, const string& brokenLetters) {
    vector<bool> b(128, false);
    for (char c : brokenLetters) {
      b[c] = true;
    }
    
    int words = 0;
    bool ok = true;
    for (char c : text) {
      if (c == ' ') {
        if (ok) {
          ++words;
        }
        ok = true;
      } else if (b[c]) {
        ok = false;
      }
    }
    return words + ok;
  }
};
