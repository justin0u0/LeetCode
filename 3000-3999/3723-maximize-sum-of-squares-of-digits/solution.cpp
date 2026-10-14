/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) {
      return "";
    }
    string s;
    s.reserve(num);
    while (num--) {
      int d = min(9, sum);
      s += d + '0';
      sum -= d;
    }
    return s;
  }
};
