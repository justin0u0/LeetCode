/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sign-of-the-product-of-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int arraySign(const vector<int>& nums) {
    bool zero = false;
    bool positive = 1;
    for (const int& num : nums) {
      if (num == 0) {
        zero = true;
      } else if (num < 0) {
        positive ^= 1;
      }
    }
    if (zero) {
      return 0;
    }
    if (positive) {
      return 1;
    }
    return -1;
  }
};
