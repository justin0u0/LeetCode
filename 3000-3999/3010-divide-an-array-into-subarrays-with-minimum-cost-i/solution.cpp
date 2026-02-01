/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumCost(const vector<int>& nums) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < min1) {
        min2 = min1;
        min1 = nums[i];
      } else if (nums[i] < min2) {
        min2 = nums[i];
      }
    }
    return nums[0] + min1 + min2;
  }
};
