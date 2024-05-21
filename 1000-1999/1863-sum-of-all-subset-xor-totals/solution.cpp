/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int subsetXORSum(const vector<int>& nums) {
    int sum = 0;
    const int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
      int xors = 0;
      for (int j = 0; j < n; ++j) {
        if ((1 << j) & i) {
          xors ^= nums[j];
        }
      }
      sum += xors;
    }
    return sum;
  }
};
