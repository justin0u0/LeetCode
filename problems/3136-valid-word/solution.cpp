/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-word/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isValid(const string& word) {
    if (word.length() < 3) {
      return false;
    }

    bool vow = false;
    bool con = false;
    bool ok = true;
    for (char c : word) {
      if (c >= 'a' && c <= 'z') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
          vow = true;
        } else {
          con = true;
        }
      } else if (c >= 'A' && c <= 'Z') {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
          vow = true;
        } else {
          con = true;
        }
      } else if (c < '0' || c > '9') {
        ok = false;
      }
    }
    return ok && vow && con;
  }
};
