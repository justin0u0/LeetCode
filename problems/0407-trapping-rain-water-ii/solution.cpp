/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/trapping-rain-water-ii/
 * Runtime: 26ms (81.82%)
 */

class Solution {
private:
  struct Grid {
    int i;
    int j;
    int h;

    bool operator<(const Grid& rhs) const {
      return h > rhs.h;
    }
  };
public:
  int trapRainWater(const vector<vector<int>>& heights) {
    const int n = heights.size();
    const int m = heights[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    priority_queue<Grid> pq;
    for (int i = 0; i < n; ++i) {
      pq.push({i, 0, heights[i][0]});
      vis[i][0] = true;
      pq.push({i, m - 1, heights[i][m - 1]});
      vis[i][m - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
      pq.push({0, i, heights[0][i]});
      vis[0][i] = true;
      pq.push({n - 1, i, heights[n - 1][i]});
      vis[n - 1][i] = true;
    }

    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};

    int sum = 0;
    while (!pq.empty()) {
      Grid u = pq.top();
      pq.pop();

      for (int i = 0; i < 4; ++i) {
        Grid v{u.i + di[i], u.j + dj[i], 0};
        if (v.i < 0 || v.i >= n || v.j < 0 || v.j >= m || vis[v.i][v.j]) {
          continue;
        }

        v.h = heights[v.i][v.j];
        if (v.h < u.h) {
          sum += u.h - v.h;
          v.h = u.h;
        }

        pq.push(v);
        vis[v.i][v.j] = true;
      }
    }

    return sum;
  }
};
