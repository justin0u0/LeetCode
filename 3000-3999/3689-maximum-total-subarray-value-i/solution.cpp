/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-total-subarray-value-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long maxTotalValue(const vector<int>& nums, const int k) {
    const auto [min, max] = ranges::minmax(nums);
    return (long long)k * (max - min);
  }
};
