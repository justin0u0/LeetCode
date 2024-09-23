/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-strings/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string addStrings(string& num1, string& num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    if (num1.length() < num2.length()) {
      swap(num1, num2);
    }
    for (int i = 0; i < num2.size(); ++i) {
      num1[i] += num2[i] - '0';
    }

    bool carry = 0;
    for (int i = 0; i < num1.size(); ++i) {
      num1[i] += carry;
      if (num1[i] > '9') {
        num1[i] -= 10;
        carry = true;
      } else {
        carry = false;
      }
    }
    if (carry) {
      num1.push_back('1');
    }
    reverse(num1.begin(), num1.end());
    return num1;
  }
};
