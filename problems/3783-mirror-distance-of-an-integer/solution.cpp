/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/mirror-distance-of-an-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int mirrorDistance(int n) {
    int num = n;
    int rev = 0;
    while (num > 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
    }
    return abs(n - rev);
  }
};
