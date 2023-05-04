/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/dota2-senate/
 * Runtime: 2ms (98.90%)
 */

class Solution {
public:
  string predictPartyVictory(string& senate) {
    int r = 0;
    int d = 0;
    for (const char& s : senate) {
      if (s == 'R') {
        ++r;
      } else {
        ++d;
      }
    }

    int skips = 0;
    char now = 0;
    while (r != 0 && d != 0) {
      int j = -1;
      int n = r + d;
      for (int i = 0; i < n; ++i) {
        char s = senate[i];
        if (skips == 0 || now == s) {
          senate[++j] = s;
          ++skips;
          now = s;
        } else {
          --skips;
          if (s == 'R') {
            --r;
          } else {
            --d;
          }
        }
      }
    }

    if (r == 0) {
      return "Dire";
    }
    return "Radiant";
  }
};
