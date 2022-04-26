/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/
 * Runtime: 109ms
 * Time Complexity: O(N^2)
 */

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = (int)points.size();

    vector<int> dist(n);
    vector<bool> vis(n, false);

    dist[0] = 0;
    vis[0] = true;
    for (int i = 0; i < n; ++i) {
      dist[i] = abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]);
    }

    int cost = 0;
    for (int i = 0; i < n - 1; ++i) {
      int u;
      int minDist = 0x3f3f3f3f;
      for (int j = 0; j < n; ++j) {
        if (!vis[j] && dist[j] < minDist) {
          minDist = dist[j];
          u = j;
        }
      }

      vis[u] = true;
      for (int j = 0; j < n; ++j) {
        dist[j] = min(dist[j], abs(points[u][0] - points[j][0]) + abs(points[u][1] - points[j][1]));
      }
      cost += minDist;
    }

    return cost;
  }
};
