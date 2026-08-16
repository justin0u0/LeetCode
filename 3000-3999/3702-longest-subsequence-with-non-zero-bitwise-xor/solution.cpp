/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int longestSubsequence(const vector<int>& nums) {
    int x = 0;
    bool allZero = true;
    for (int num : nums) {
      x ^= num;
      if (num > 0) {
        allZero = false;
      }
    }
    if (allZero) {
      return 0;
    }
    if (x == 0) {
      return nums.size() - 1;
    }
    return nums.size();
  }
};
