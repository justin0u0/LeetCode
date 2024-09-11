/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fraction-addition-and-subtraction/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string fractionAddition(const string& expression) {
    stringstream ss(expression);

    char op = '+';

    int a = 0;
    int b = 1;

    int x;
    int y;
    char c;
    while (ss >> x >> c >> y) {
      int n = a * y + b * x;
      int d = b * y;
      int g = __gcd(n, d);
      a = n / g;
      b = d / g;
      if (b < 0) {
        a *= -1;
        b *= -1;
      }
    }
    return to_string(a) + '/' + to_string(b);
  }
};
