/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int uniqueXorTriplets(const vector<int>& nums) {
    const auto n = nums.size();
    if (n <= 2) {
      return n;
    }
    int res = 1;
    while (res <= n) {
      res <<= 1;
    }
    return res;
  }
};
