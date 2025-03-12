/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumCount(const vector<int>& nums) {
    int pos = 0;
    int neg = 0;
    for (int num : nums) {
      if (num > 0) {
        ++pos;
      } else if (num < 0) {
        ++neg;
      }
    }
    return max(pos, neg);
  }
};
