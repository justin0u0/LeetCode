/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-sightseeing-pair/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxScoreSightseeingPair(const vector<int>& values) {
    int mx = 0;
    int res = 0;
    for (int i = 0; i < values.size(); ++i) {
      res = max(res, mx + values[i] - i);
      mx = max(mx, values[i] + i);
    }
    return res;
  }
};
