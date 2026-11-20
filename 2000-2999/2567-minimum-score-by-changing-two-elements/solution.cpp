/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-score-by-changing-two-elements/
 * Runtime: 15ms (62.50%)
 */

class Solution {
public:
  int minimizeSum(vector<int>& nums) {
    const int n = nums.size();

    ranges::sort(nums);
    return min({
      nums[n - 1] - nums[2],
      nums[n - 2] - nums[1],
      nums[n - 3] - nums[0]
    });
  }
};
