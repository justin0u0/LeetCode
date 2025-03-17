/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-array-into-equal-pairs/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool divideArray(vector<int>& nums) {
    int count[501] = {0};
    for (int num : nums) {
      ++count[num];
    }
    for (int num : nums) {
      if (count[num] & 1) {
        return false;
      }
    }
    return true;
  }
};
