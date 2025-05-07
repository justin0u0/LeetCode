/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
 * Runtime: 19ms (76.17%)
 */

class Solution {
private:
  typedef pair<int, pair<int, int>> PIII;
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    const int n = moveTime.size();
    const int m = moveTime[0].size();

    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;
    pq.push({0, {0, 0}});

    vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));
    dist[0][0] = 0;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      const auto [x, y] = u;
      pq.pop();

      if (dist[x][y] < d) {
        continue;
      }

      for (int i = 0; i < 4; ++i) {
        const int x2 = x + dx[i];
        const int y2 = y + dy[i];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
          continue;
        }

        const int d2 = max(d, moveTime[x2][y2]) + 1;
        if (dist[x2][y2] > d2) {
          dist[x2][y2] = d2;
          pq.push({d2, {x2, y2}});
        }
      }
    }

    return dist[n - 1][m - 1];
  }
};
