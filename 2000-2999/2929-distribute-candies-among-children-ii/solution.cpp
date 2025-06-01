/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/distribute-candies-among-children-ii/
 * Runtime: 35ms (12.94%)
 */

class Solution {
public:
  long long distributeCandies(const int n, const int limit) {
    const int l2 = (limit << 1);

    long long dist = 0;
    for (int i = limit; i >= 0; --i) {
      const int left = n - i;
      if (left > l2) {
        break;
      }

      const int x = max(0, left - limit);
      dist += max(0, left + 1 - x - x);
    }
    return dist;
  }
};
