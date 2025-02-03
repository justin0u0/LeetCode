/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int incr = 1;
    int decr = 1;
    int longest = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        longest = max(longest, ++incr);
        decr = 1;
      } else if (nums[i] < nums[i - 1]) {
        longest = max(longest, ++decr);
        incr = 1;
      } else {
        incr = 1;
        decr = 1;
      }
    }
    return longest;
  }
};
