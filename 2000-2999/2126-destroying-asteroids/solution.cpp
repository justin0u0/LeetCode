/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/destroying-asteroids/
 * Runtime: 35ms (46.71%)
 */

class Solution {
public:
  bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
    ranges::sort(asteroids);
    for (const int a : asteroids) {
      if (a > mass) {
        return false;
      }
      mass += a;
    }
    return true;
  }
};
