/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countSubarrays(const vector<int>& nums) {
    int arrs = 0;
    for (int i = 1; i < nums.size() - 1; ++i) {
      if ((nums[i - 1] + nums[i + 1]) << 1 == nums[i]) {
        ++arrs;
      }
    }
    return arrs;
  }
};
