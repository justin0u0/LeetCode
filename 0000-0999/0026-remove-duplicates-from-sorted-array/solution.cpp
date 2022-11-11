/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Runtime: 7ms (98.66%)
 */

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int l = 0;
    for (const int& num : nums) {
      if (l == 0 || nums[l - 1] != num) {
        nums[l++] = num;
      }
    }

    return l;
  }
};
