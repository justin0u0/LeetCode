/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-degree-of-a-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int reverseDegree(const string& s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      ans += (26 - s[i] + 'a') * (i + 1);
    }
    return ans;
  }
};
