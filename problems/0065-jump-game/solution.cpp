/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/jump-game/
 * Runtime: 66ms (93.40%)
 */

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farest = 0;
    for (int i = 0; i < n; ++i) {
      if (i > farest) {
        return false;
      }

      farest = max(farest, i + nums[i]);
    }

    return true;
  }
};
