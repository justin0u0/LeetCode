/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/running-sum-of-1d-array/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> sum(nums.size());
    sum[0] = nums[0];

    int n = (int)nums.size();
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + nums[i];
    }

    return sum;
  }
};
