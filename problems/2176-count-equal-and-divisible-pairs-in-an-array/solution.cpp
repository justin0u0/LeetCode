/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countPairs(vector<int>& nums, int k) {
    const int n = nums.size();
    int pairs = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] == nums[j] && i * j % k == 0) {
          ++pairs;
        }
      }
    }
    return pairs;
  }
};
