/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countPartitions(const vector<int>& nums) {
    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);
    int pars = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      left += nums[i];
      right -= nums[i];
      if (!((left - right) & 1)) {
        ++pars;
      }
    }
    return pars;
  }
};
