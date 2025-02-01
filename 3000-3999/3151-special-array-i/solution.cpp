/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/special-array-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isArraySpecial(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if ((nums[i] & 1) ^ (nums[i - 1] & 1) == 0) {
        return false;
      }
    }
    return true;
  }
};
