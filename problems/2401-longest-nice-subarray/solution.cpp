/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-nice-subarray/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int mask = 0;

    int j = 0;
    int longest = 0;
    for (int i = 0; i < nums.size(); i++) {
      while ((nums[i] & mask) != 0) {
        mask ^= nums[j];
        ++j;
      }
      mask |= nums[i];
      longest = max(longest, i - j + 1);
    }
    return longest;
  }
};
