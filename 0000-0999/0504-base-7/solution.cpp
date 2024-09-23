/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/base-7/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0) {
      return "0";
    }

    if (num < 0) {
      return '-' + convertToBase7(-num);
    }

    string res;
    while (num != 0) {
      res.push_back(num % 7 + '0');
      num /= 7;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
