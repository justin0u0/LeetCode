/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
 * Runtime: 1ms (54.29%)
 */

class Solution {
public:
  int sortPermutation(const vector<int>& nums) {
    int k = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i) {
        k &= nums[i];
      }
    }
    if (k == INT_MAX) {
      return 0;
    }
    return k;
  }
};
