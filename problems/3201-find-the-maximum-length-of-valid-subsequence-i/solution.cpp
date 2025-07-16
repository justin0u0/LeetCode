/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int o = 0;
    int e = 0;
    int alt = 0;
    bool next = (nums[0] & 1);
    for (int num : nums) {
      if (num & 1) {
        ++o;
      } else {
        ++e;
      }
      if ((num & 1) == next) {
        next ^= 1;
        ++alt;
      }
    }
    return max(max(o, e), alt);
  }
};
