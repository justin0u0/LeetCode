/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * Runtime: 62ms
 */

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = (int)grid.size();

    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
      return -1;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;

    for (int steps = 1; !q.empty(); ++steps) {
      int sz = (int)q.size();
      while (sz--) {
        pair<int, int> u = q.front();
        q.pop();
        
        if (u.first == n - 1 && u.second == n - 1) {
          return steps;
        }

        for (int i = -1; i < 2; ++i) {
          for (int j = -1; j < 2; ++j) {
            pair<int, int> v{u.first + i, u.second + j};
            
            if (v.first < 0 || v.second < 0 || v.first >= n || v.second >= n || grid[v.first][v.second] != 0) {
              continue;
            }

            q.push(v);
            grid[v.first][v.second] = 1;
          }
        }
      }
    }

    return -1;
  }
};
