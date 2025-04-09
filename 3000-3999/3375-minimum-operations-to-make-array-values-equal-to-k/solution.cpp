/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
 * Runtime: 7ms (89.94%)
 */

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ops = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < k) {
        return -1;
      }
      if (nums[i] > k && (i == 0 || nums[i] != nums[i - 1])) {
        ++ops;
      }
    }
    return ops;
  }
};
