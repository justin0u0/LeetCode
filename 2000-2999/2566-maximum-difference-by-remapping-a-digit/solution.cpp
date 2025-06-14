/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minMaxDifference(int num) {
    string s = to_string(num);

    int mx = INT_MIN;
    int mn = INT_MAX;
    for (int i = '0'; i <= '9'; ++i) {
      for (int j = 0; j <= 9; ++j) {
        int x = 0;
        for (char c : s) {
          if (c == i) {
            x = x * 10 + j;
          } else {
            x = x * 10 + c - '0';
          }
        }
        mx = max(mx, x);
        mn = min(mn, x);
      }
    }
    return mx - mn;
  }
};
