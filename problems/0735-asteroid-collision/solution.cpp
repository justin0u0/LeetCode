/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/asteroid-collision/
 * Runtime: 9ms (93.89%)
 */

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    int j = -1;
    int n = asteroids.size();
    for (int i = 0; i < n; ++i) {
      if (asteroids[i] > 0) {
        asteroids[++j] = asteroids[i];
        continue;
      }

      while (j >= 0 && asteroids[j] > 0 && asteroids[j] < abs(asteroids[i])) {
        --j;
      }
      if (j >= 0 && asteroids[j] > 0 && asteroids[j] == abs(asteroids[i])) {
        --j;
        continue;
      }
      if (j < 0 || asteroids[j] < 0) {
        asteroids[++j] = asteroids[i];
      }
    }
    asteroids.resize(j + 1);
    return asteroids;
  }
};
