/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/target-sum/
 * Runtime: 14ms (61.20%)
 */

class Solution {
public:
  int findTargetSumWays(const vector<int>& nums, const int target) {
    const int b = 1000;
    const int n = 2001;

    vector<int> pre(n);
    pre[b] = 1;
    vector<int> cur(n);

    for (int num : nums) {
      for (int j = 0; j < n; ++j) {
        cur[j] = 0;
        if (j - num >= 0) {
          cur[j] += pre[j - num];
        }
        if (j + num < n) {
          cur[j] += pre[j + num];
        }
      }
      swap(pre, cur);
    }

    return pre[target + b];
  }
};
