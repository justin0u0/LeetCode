/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-it-is-a-straight-line/
 * Runtime: 3ms (99.52%)
 */

class Solution {
private:
  inline int cross(const int v1[2], const int v2[2]) {
    return v1[0] * v2[1] - v2[0] * v1[1];
  }
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n <= 2) {
      return true;
    }

    int x = coordinates[0][0];
    int y = coordinates[0][1];
    int v1[2] = {coordinates[1][0] - x, coordinates[1][1] - y};
    for (int i = 2; i < n; ++i) {
      int v2[2] = {coordinates[i][0] - x, coordinates[i][1] - y};
      if (cross(v1, v2) != 0) {
        return false;
      }
    }

    return true;
  }
};
