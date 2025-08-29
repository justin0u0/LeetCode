/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/alice-and-bob-playing-flower-game/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long flowerGame(const int n, const int m) {
    return (long long)((n + 1) / 2) * (m / 2) + (long long)(n / 2) * ((m + 1) / 2);
  }
};
