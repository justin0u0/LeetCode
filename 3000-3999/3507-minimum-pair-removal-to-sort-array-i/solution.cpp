/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
 * Runtime: 6ms (23.25%)
 */

class Solution {
public:
  int minimumPairRemoval(vector<int>& nums) {
    vector<int> next;
    for (int res = 0; ; ++res) {
      bool ok = true;
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] > nums[i + 1]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return res;
      }

      int j;
      int sum = INT_MAX;
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] + nums[i + 1] < sum) {
          sum = nums[i] + nums[i + 1];
          j = i;
        }
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (i == j) {
          next.emplace_back(nums[i] + nums[i + 1]);
          ++i;
        } else {
          next.emplace_back(nums[i]);
        }
      }
      swap(nums, next);
      next.clear();
    }
    return -1;
  }
};
