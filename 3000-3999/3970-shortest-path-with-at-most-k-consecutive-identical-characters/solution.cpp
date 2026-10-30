/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
 * Runtime: 206ms (70.80%)
 */

class Solution {
public:
  int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    vector<vector<pair<int, int>>> neigh(n);
    for (const auto& e : edges) {
      neigh[e[0]].push_back({e[1], e[2]});
    }

    // dist[i][j]: minimum distance from 0 to i with j+1 consecutive characters
    //  in the most recent.
    vector<vector<int>> dist(n, vector<int>(k, 0x3f3f3f3f));
    dist[0][0] = 0;

    using T3 = tuple<int, int, int>;
    priority_queue<T3, vector<T3>, greater<T3>> pq; // d, u, cnt
    pq.push({0, 0, 0});

    while (!pq.empty()) {
      const auto [d, u, cnt] = pq.top();
      pq.pop();

      if (u == n - 1) {
        return d;
      }
      if (d > dist[u][cnt]) {
        continue;
      }

      for (const auto& [v, w] : neigh[u]) {
        int nextCnt = 0;
        if (labels[v] == labels[u]) {
          nextCnt = cnt + 1;
        }
        if (nextCnt >= k) {
          continue;
        }
        if (dist[v][nextCnt] > d + w) {
          dist[v][nextCnt] = d + w;
          pq.push({d + w, v, nextCnt});
        }
      }
    }
    
    return -1;
  }
};
