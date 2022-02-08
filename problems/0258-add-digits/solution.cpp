/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-digits/
 * Runtime: 0ms
 */

class Solution {
public:
  int addDigits(int num) {
    return (num - 1) % 9 + 1;
  }
};
