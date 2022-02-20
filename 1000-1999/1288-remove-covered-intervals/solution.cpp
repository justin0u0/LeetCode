/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-covered-intervals/
 * Runtime: 27ms
 * Time Complexity: O(NlogN)
 */

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    vector<pair<int, int>> box;
    for (vector<int>& interval : intervals) {
      box.emplace_back(interval[0], -interval[1]);
    }

    sort(box.begin(), box.end());

    int right = -1;
    int remains = 0;
    for (pair<int, int>& p : box) {
      int r = -p.second;
      if (r > right) {
        right = r;
        ++remains;
      }
    }

    return remains;
  }
};
