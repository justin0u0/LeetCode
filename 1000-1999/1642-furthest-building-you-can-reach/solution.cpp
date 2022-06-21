/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/furthest-building-you-can-reach/
 * Runtime: 144ms
 */

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = (int)heights.size();
    int i;
    for (i = 0; i < n - 1; ++i) {
      int diff = heights[i + 1] - heights[i];
      if (diff > 0) {
        pq.push(diff);
        if (pq.size() > ladders) {
          int b = pq.top();
          pq.pop();
          if (bricks < b) {
            return i;
          }

          bricks -= b;
        }
      }
    }

    return n - 1;
  }
};
