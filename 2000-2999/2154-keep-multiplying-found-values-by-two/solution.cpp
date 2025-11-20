/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findFinalValue(const vector<int>& nums, int original) {
    bitset<2001> vis;
    for (int num : nums) {
      vis.set(num);
    }
    while (vis.test(original)) {
      original <<= 1;
    }
    return original;
  }
};
