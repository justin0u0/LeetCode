/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-positive-sum-subarray/
 * Runtime: 1ms (62.00%)
 */

class Solution {
public:
  int minimumSumSubarray(const vector<int>& nums, const int l, const int r) {
    const int n = nums.size();

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i, len = 1; j >= 0; --j, ++len) {
        sum += nums[j];
        if (len >= l && len <= r && sum > 0) {
          res = min(res, sum);
        }
      }
    }

    if (res == INT_MAX) {
      return -1;
    }
    return res;
  }
};
