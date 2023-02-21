/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * Runtime: 16ms (99.39%)
 */

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    int l = 0;
    int r = nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (((mid & 1) && nums[mid - 1] != nums[mid]) || (!(mid & 1) && nums[mid + 1] != nums[mid])) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return nums[r];
  }
};
