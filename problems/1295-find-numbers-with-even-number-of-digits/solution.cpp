/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
      int digits = 0;
      while (num != 0) {
        ++digits;
        num /= 10;
      }
      res += (digits & 1);
    }
    return nums.size() - res;
  }
};
