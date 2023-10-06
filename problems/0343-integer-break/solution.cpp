/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/integer-break/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int integerBreak(int n) {
    double answer = 0;
    for (int i = 2; i <= n; ++i) {
      int x = n / i;
      int y = n % i;
      answer = max(answer, pow(x, i - y) * pow(x + 1, y));
    }
    return answer;
  }
};
