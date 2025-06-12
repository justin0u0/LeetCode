/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxAdjacentDistance(const vector<int>& nums) {
    int maxa = abs(nums.back() - nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      maxa = max(maxa, abs(nums[i] - nums[i - 1]));
    }
    return maxa;
  }
};
