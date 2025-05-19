/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/type-of-triangle/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string triangleType(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums[0] + nums[1] <= nums[2]) {
      return "none";
    }
    if (nums[0] == nums[2]) {
      return "equilateral";
    }
    if (nums[0] == nums[1] || nums[1] == nums[2]) {
      return "isosceles";
    }
    return "scalene";
  }
};
