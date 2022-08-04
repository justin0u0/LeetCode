/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/mirror-reflection/
 * Runtime: 0ms
 */

class Solution {
public:
  int mirrorReflection(int p, int q) {
    int gcd = __gcd(p, q);
    bool right = (p / gcd) & 1;
    if (right) {
      return ((q / gcd) & 1) ? 1 : 0;
    }

    return ((q / gcd) & 1) ? 2 : -1;
  }
};
