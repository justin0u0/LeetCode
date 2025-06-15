/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxDiff(int num) {
    string s = to_string(num);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = '0'; i <= '9'; ++i) {
      for (int j = 0; j <= 9; ++j) {
        if (s[0] == i && j == 0) {
          continue;
        }
        int x = 0;
        for (char c : s) {
          if (c == i) {
            x = x * 10 + j;
          } else {
            x = x * 10 + c - '0';
          }
        }

        mn = min(mn, x);
        mx = max(mx, x);
      }
    }
    return mx - mn;
  }
};
