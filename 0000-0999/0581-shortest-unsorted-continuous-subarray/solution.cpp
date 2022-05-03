/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * Runtime: 31ms
 */

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = (int)nums.size();
    int r = -2;
    int maxVal = nums[0];
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= maxVal) {
        maxVal = nums[i];
      } else {
        r = i;
      }
    }

    int l = -1;
    int minVal = nums[n - 1];
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] <= minVal) {
        minVal = nums[i];
      } else {
        l = i;
      }
    }

    return r - l + 1;
  }
};
