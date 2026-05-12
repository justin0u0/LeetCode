/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
 * Runtime: 31ms (83.98%)
 */

class Solution {
public:
  int minimumEffort(vector<vector<int>>& tasks) {
    ranges::sort(tasks, greater<>(), [](const auto& t) {
      return t[1] - t[0];
    });
    int res = 0;
    int sum = 0;
    for (const auto& t : tasks) {
      res = max(res, sum + t[1]);
      sum += t[0];
    }
    return res;
  }
};
