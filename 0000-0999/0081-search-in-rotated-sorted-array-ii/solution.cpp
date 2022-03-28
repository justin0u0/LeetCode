/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * Runtime: 4ms
 */

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = (int)nums.size();
    while (l < r) {
      int mid = (l + r) >> 1;

      if (nums[mid] == target) {
        return true;
      }

      if (nums[l] == nums[r - 1]) {
        ++l;
      } else {
        bool sameSide = (target < nums[l] && nums[mid] < nums[l]) || (target >= nums[l] && nums[mid] >= nums[l]);
        if ((sameSide && nums[mid] < target) || (!sameSide && nums[mid] >= target)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
    }

    return false;
  }
};
