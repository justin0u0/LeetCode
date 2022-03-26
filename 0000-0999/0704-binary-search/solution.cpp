/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-search/
 * Runtime: 43ms
 */

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = (int)nums.size();

    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return -1;
  }
};
