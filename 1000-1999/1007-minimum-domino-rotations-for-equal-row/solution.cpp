/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 * Runtime: 108ms
 */

class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int top = tops[0];
    int bottom = bottoms[0];

    int count[4] = {0};
    int n = (int)tops.size();
    const int INF = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
      if (tops[i] != top && bottoms[i] != top) {
        count[0] = INF;
        count[1] = INF;
      }
      if (tops[i] != bottom && bottoms[i] != bottom) {
        count[2] = INF;
        count[3] = INF;
      }

      if (tops[i] != top) {
        ++count[0];
      }
      if (bottoms[i] != top) {
        ++count[1];
      }
      if (tops[i] != bottom) {
        ++count[2];
      }
      if (bottoms[i] != bottom) {
        ++count[3];
      }
    }

    int answer = min(min(count[0], count[1]), min(count[2], count[3]));
    if (answer >= INF) {
      return -1;
    }

    return answer;
  }
};
