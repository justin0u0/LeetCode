/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-colors/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;
    while (j <= k) {
      if (nums[j] == 0) {
        swap(nums[i], nums[j]);
        ++i;
        ++j;
      } else if (nums[j] == 1) {
        ++j;
      } else { // nums[j] == 2
        swap(nums[j], nums[k]);
        --k;
      }
    }
  }
};
