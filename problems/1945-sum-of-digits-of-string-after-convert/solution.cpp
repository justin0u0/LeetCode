/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline int sumDigits(int x) {
    int sum = 0;
    while (x != 0) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  }
public:
  int getLucky(const string& s, int k) {
    int sum = 0;
    for (char c : s) {
      sum += sumDigits(c - 'a' + 1);
    }

    k--;
    while (k--) {
      sum = sumDigits(sum);
    }
    return sum;
  }
};
