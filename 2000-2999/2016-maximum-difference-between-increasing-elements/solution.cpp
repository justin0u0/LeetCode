/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumDifference(vector<int>& nums) {
    int mn = INT_MAX;
    int maxd = 0;
    for (int i = 0; i < nums.size(); ++i) {
      mn = min(mn, nums[i]);
      maxd = max(maxd, nums[i] - mn);
    }
    if (maxd <= 0) {
      return -1;
    }
    return maxd;
  }
};
