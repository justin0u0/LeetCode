/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/calculate-digit-sum-of-a-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string digitSum(string s, int k) {
    while (s.length() > k) {
      string next;
      for (int i = 0; i < s.length(); i += k) {
        int sum = 0;
        for (int j = i; j < i + k && j < s.length(); ++j) {
          sum += s[j] - '0';
        }
        next += to_string(sum);
      }
      s = move(next);
    }
    return s;
  }
};
