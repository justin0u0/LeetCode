/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 * Runtime: 17ms (96.29%)
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */

class Solution {
private:
  int pre[1002];
  int cur[1002];
public:
  int minimumDeleteSum(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();
    pre[0] = 0;
    for (int j = 0; j < m; ++j) {
      pre[j + 1] = pre[j] + s2[j];
    }
    for (int i = 0; i < n; ++i) {
      cur[0] = pre[0] + s1[i];
      for (int j = 0; j < m; ++j) {
        if (s1[i] == s2[j]) {
          cur[j + 1] = pre[j];
        } else {
          cur[j + 1] = min(pre[j + 1] + s1[i], cur[j] + s2[j]);
        }
      }
      swap(pre, cur);
    }
    return pre[m];
  }
};
