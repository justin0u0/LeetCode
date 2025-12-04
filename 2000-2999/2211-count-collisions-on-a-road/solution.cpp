/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-collisions-on-a-road/
 * Runtime: 8ms (78.26%)
 */

class Solution {
public:
  int countCollisions(const string& directions) {
    const int n = directions.size();

    int i;
    bool hasS = false;
    for (i = 0; i < n; ++i) {
      if (directions[i] == 'R' || (hasS && directions[i] == 'L')) {
        break;
      }
      if (directions[i] == 'S') {
        hasS = true;
      }
    }

    int j;
    hasS = false;
    for (j = n - 1; j >= i; --j) {
      if (directions[j] == 'L' || (hasS && directions[j] == 'R')) {
        break;
      }
      if (directions[j] == 'S') {
        hasS = true;
      }
    }

    int s = 0;
    for (int k = i; k <= j; ++k) {
      if (directions[k] == 'S') {
        ++s;
      }
    }

    return j - i + 1 - s;
  }
};
