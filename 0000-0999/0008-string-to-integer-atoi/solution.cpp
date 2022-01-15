/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/string-to-integer-atoi/
 * Runtime: 12ms
 */

class Solution {
public:
  int myAtoi(string s) {
    if (s.empty()) {
      return 0;
    }

    int n = (int)s.length();

    int i = 0;
    while (i < n && s[i] == ' ') {
      ++i;
    }

    if (i == n) {
      return 0;
    }

    int base = 1;
    if (s[i] == '-') {
      base = -1;
      ++i;
    } else if (s[i] == '+') {
      ++i;
    }

    if (i == n) {
      return 0;
    }

    long long sum = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
      sum = sum * 10 + base * (s[i] - '0');

      if (base == -1 && sum < INT_MIN) {
        return INT_MIN;
      }
      if (base == 1 && sum > INT_MAX) {
        return INT_MAX;
      }

      ++i;
    }

    return sum;
  }
};
