/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * Runtime: 4ms (71.58%)
 */

class Solution {
public:
  int minInsertions(const string& s) {
    const int n = s.length();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        ++cnt;
      } else {
        if (i + 1 >= n || s[i + 1] == '(') {
          ++ans;
        } else {
          ++i;
        }
        --cnt;
        if (cnt < 0) {
          ++ans;
          cnt = 0;
        }
      }
    }
    return ans + cnt * 2;
  }
};
