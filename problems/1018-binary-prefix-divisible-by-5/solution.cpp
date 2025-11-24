/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-prefix-divisible-by-5/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<bool> prefixesDivBy5(const vector<int>& nums) {
    vector<bool> res;
    res.reserve(nums.size());

    int x = 0;
    for (int num : nums) {
      x = ((x << 1) | (num == 1)) % 5;
      res.emplace_back(x == 0);
    }
    return res;
  }
};
