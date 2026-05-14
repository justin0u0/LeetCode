/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-array-is-good/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isGood(vector<int>& nums) {
    const int n = nums.size();
    if (n < 2) {
      return false;
    }

    ranges::sort(nums);
    for (int i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return false;
      }
    }
    return nums[n - 1] == nums[n - 2];
  }
};
