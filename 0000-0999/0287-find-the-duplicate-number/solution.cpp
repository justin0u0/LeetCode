/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-duplicate-number/
 * Runtime: 84ms
 */

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] != i + 1) {
        if (nums[i] == nums[nums[i] - 1]) {
          return nums[i];
        }

        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    return -1;
  }
};
