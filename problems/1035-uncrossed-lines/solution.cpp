/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/uncrossed-lines/
 * Runtime: 6ms (98.72%)
 */

class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<int> pre(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          cur[j] = pre[j - 1] + 1;
        } else {
          cur[j] = max(pre[j], cur[j - 1]);
        }
      }
      swap(pre, cur);
    }
    return pre[m];
  }
};
