/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-distance-to-closest-person/
 * Runtime: 24ms
 */

class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    const int INF = 0x3f3f3f3f;
    int n = (int)seats.size();

    vector<int> rDist(n + 1, 0);
    rDist[n] = INF;
    for (int i = n - 1; i >= 0; --i) {
      if (!seats[i]) {
        rDist[i] = rDist[i + 1] + 1;
      }
    }

    int lDist = INF;
    int maxDist = 0;
    for (int i = 0; i < n; ++i) {
      if (!seats[i]) {
        ++lDist;
      } else {
        lDist = 0;
      }

      maxDist = max(maxDist, min(lDist, rDist[i]));
    }

    return maxDist;
  }
};
