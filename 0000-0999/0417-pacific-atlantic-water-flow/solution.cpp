/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pacific-atlantic-water-flow/
 * Runtime: 47ms
 */

class Solution {
private:
  int n;
  int m;
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};

  void bfs(const vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
    while (!q.empty()) {
      pair<int, int> u = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        pair<int, int> v{u.first + dx[i], u.second + dy[i]};
        if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m || vis[v.first][v.second] || heights[v.first][v.second] < heights[u.first][u.second]) {
          continue;
        }

        q.push(v);
        vis[v.first][v.second] = true;
      }
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();
    m = heights[0].size();

    queue<pair<int, int>> q1;
    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    queue<pair<int, int>> q2;
    vector<vector<bool>> vis2(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
      q1.push({i, 0});
      vis1[i][0] = true;
      q2.push({i, m - 1});
      vis2[i][m - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
      q1.push({0, i});
      vis1[0][i] = true;
      q2.push({n - 1, i});
      vis2[n - 1][i] = true;
    }

    bfs(heights, q1, vis1);
    bfs(heights, q2, vis2);

    vector<vector<int>> answer;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis1[i][j] && vis2[i][j]) {
          answer.emplace_back(vector<int>{i, j});
        }
      }
    }

    return answer;
  }
};
