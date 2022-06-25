/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/non-decreasing-array/
 * Runtime: 30ms
 */

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int cur = -1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        if (cur != -1) {
          return false;
        }
        cur = i;
      }
    }

    if (cur - 2 >= 0 && nums[cur] < nums[cur - 2] && cur + 1 < nums.size() && nums[cur - 1] > nums[cur + 1]) {
      return false;
    }

    return true;
  }
};
