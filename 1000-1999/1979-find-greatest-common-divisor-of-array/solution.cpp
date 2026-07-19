/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findGCD(vector<int>& nums) {
    ranges::sort(nums.begin(), nums.end());
    return gcd(nums.front(), nums.back());
  }
};
