/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Runtime: 7ms
 */

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size();
    while (l < r) {
      int mid = (l + r) >> 1;

      if (nums[mid] == target) {
        return mid;
      }

      bool sameSide = (target < nums[0] && nums[mid] < nums[0]) || (target >= nums[0] && nums[mid] >= nums[0]);
      if ((sameSide && nums[mid] < target) || (!sameSide && nums[mid] >= target)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return -1;
  }
};

