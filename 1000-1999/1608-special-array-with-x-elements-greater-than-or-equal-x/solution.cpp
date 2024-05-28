/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    const int n = nums.size();
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      while (j < n && nums[j] < i) {
        ++j;
      }
      if (i == n - j) {
        return i;
      }
    }
    return -1;
  }
};
