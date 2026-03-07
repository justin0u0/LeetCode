/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
 * Runtime: 3ms (96.40%)
 */

class Solution {
public:
  int minFlips(const string& s) {
    const int n = s.length();

    int flips = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != ((i & 1) + '0')) {
        ++flips;
      }
    }

    int res = min(flips, n - flips);
    if (n & 1) {
      for (int i = 0; i < n; ++i) {
        if (s[i] != ((i & 1) + '0')) {
          --flips;
        } else {
          ++flips;
        }
        res = min(res, min(flips, n - flips));
      }
    }
    return res;
  }
};
