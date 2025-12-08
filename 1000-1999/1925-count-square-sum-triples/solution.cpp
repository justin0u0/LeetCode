/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-square-sum-triples/
 * Runtime: 6ms (68.58%)
 */

class Solution {
public:
  int countTriples(const int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        const int s = sqrt(i * i + j * j);
        if (s <= n && i * i + j * j == s * s) {
          ++count;
        }
      }
    }
    return count;
  }
};
