/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/vowels-game-in-a-string/
 * Runtime: 4ms (72.76%)
 */

class Solution {
public:
  bool doesAliceWin(const string& s) {
    for (const char c : s) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
      }
    }
    return false;
  }
};
