/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-ascending-subarray-sum/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxAscendingSum(const vector<int>& nums) {
    int sum = nums[0];
    int mx = sum;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] <= nums[i - 1]) {
        sum = nums[i];
      } else {
        sum += nums[i];
      }
      mx = max(mx, sum);
    }
    return mx;
  }
};
