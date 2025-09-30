/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-triangular-sum-of-an-array/
 * Runtime: 51ms (85.15%)
 */

class Solution {
public:
  int triangularSum(vector<int>& nums) {
    const int n = nums.size();
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n - i; ++j) {
        nums[j] = (nums[j] + nums[j + 1]) % 10;
      }
    }
    return nums[0];
  }
};
