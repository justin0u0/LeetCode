/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-refueling-stops/
 * Runtime: 26ms
 */

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int fuel = startFuel;
    int refuels = 0;
    int pos = 0;

    priority_queue<int> pq;
    stations.emplace_back(vector<int>{target, 0});
    for (const vector<int>& s : stations) {
      int dist = s[0] - pos;
      while (fuel - dist < 0) {
        if (pq.empty()) {
          return -1;
        }
        fuel += pq.top();
        pq.pop();
        ++refuels;
      }
      fuel -= dist;
      pos = s[0];
      pq.push(s[1]);
    }

    return refuels;
  }
};
