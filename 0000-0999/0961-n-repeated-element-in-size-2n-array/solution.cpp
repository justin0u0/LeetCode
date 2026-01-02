/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int repeatedNTimes(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i += 2) {
      if (nums[i] == nums[i + 1]) {
        return nums[i];
      }
    }
    if (nums[0] == nums[2] || nums[0] == nums[3]) {
      return nums[0];
    }
    return nums[1];
  }
};
