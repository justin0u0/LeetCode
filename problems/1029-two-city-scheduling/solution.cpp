/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-city-scheduling/
 * Runtime: 8ms
 */

class Solution {
private:
  static bool compare(vector<int>& a, vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
  }
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), Solution::compare);

    int answer = 0;
    int n = (int)costs.size();
    for (int i = 0; i < n / 2; ++i) {
      answer += costs[i][0];
    }
    for (int i = n / 2; i < n; ++i) {
      answer += costs[i][1];
    }

    return answer;
  }
};
