/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rotate-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int f[101];
public:
  bool rotateString(const string& s, string& goal) {
    if (s.length() != goal.length()) {
      return false;
    }
    goal += goal;

    f[0] = 0;
    int j = 0;
    for (int i = 1; i < s.length(); ++i) {
      while (j != 0 && s[i] != s[j]) {
        j = f[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      f[i] = j;
    }

    j = 0;
    for (int i = 0; i < goal.length(); ++i) {
      while (j != 0 && goal[i] != s[j]) {
        j = f[j - 1];
      }
      if (goal[i] == s[j]) {
        ++j;
      }
      if (j == s.length()) {
        return true;
      }
    }

    return false;
  }
};
