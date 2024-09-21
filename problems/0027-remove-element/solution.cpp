/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-element/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int removeElement(vector<int>& nums, const int val) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }
    return j;
  }
};
