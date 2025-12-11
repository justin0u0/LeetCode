/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-covered-buildings/
 * Runtime: 25ms (90.06%)
 */

class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    vector<int> left(n + 1, INT_MAX);
    vector<int> right(n + 1, INT_MIN);
    vector<int> up(n + 1, INT_MAX);
    vector<int> down(n + 1, INT_MIN);

    for (const auto& pos : buildings) {
      const int x = pos[0];
      const int y = pos[1];
      left[y] = min(left[y], x);
      right[y] = max(right[y], x);
      up[x] = min(up[x], y);
      down[x] = max(down[x], y);
    }

    int count = 0;
    for (const auto& pos : buildings) {
      const int x = pos[0];
      const int y = pos[1];
      if (left[y] < x && x < right[y] && up[x] < y && y < down[x]) {
        ++count;
      }
    }
    return count;
  }
};
