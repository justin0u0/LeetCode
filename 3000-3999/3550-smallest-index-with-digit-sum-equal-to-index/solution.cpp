/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int smallestIndex(const vector<int>& nums) {
    for (const auto [i, num] : nums | views::enumerate) {
      int sum = 0;
      for (int x = num; x > 0; x /= 10) {
        sum += x % 10;
      }
      if (sum == i) {
        return i;
      }
    }
    return -1;
  }
};
