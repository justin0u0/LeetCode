/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countHillValley(vector<int>& nums) {
    const int n = nums.size();

    int m = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[i - 1]) {
        nums[m++] = nums[i];
      }
    }

    int hv = 0;
    for (int i = 1; i < m - 1; ++i) {
      if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
        ++hv;
      } else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        ++hv;
      }
    }
    return hv;
  }
};
