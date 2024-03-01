/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-odd-binary-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string maximumOddBinaryNumber(string& s) {
    int zeros = count(s.begin(), s.end(), '0');
    int ones = s.length() - zeros;
    s.clear();
    s.append(ones - 1, '1');
    s.append(zeros, '0');
    s.push_back('1');
    return s;
  }
};
