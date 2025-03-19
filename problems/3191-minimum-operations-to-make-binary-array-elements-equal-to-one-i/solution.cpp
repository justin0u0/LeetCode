/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();

    int ops = 0;
    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] == 0) {
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        ++ops;
      }
    }

    if (nums[n - 1] == 0 || nums[n - 2] == 0) {
      return -1;
    }
    return ops;
  }
};
