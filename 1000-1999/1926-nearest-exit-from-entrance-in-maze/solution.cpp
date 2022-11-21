/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 * Runtime: 126ms (95.18%)
 */

class Solution {
private:
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size();
    int m = maze[0].size();

    queue<pair<int, int>> q;
    queue<pair<int, int>> qNext;
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';

    for (int dist = 0; !q.empty(); ++dist) {
      while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
          int newx = p.first + dx[i];
          int newy = p.second + dy[i];
          if (newx < 0 || newy < 0 || newx >= n || newy >= m || maze[newx][newy] == '+') {
            continue;
          }

          if (newx == 0 || newy == 0 || newx == n - 1 || newy == m - 1) {
            return dist + 1;
          }

          qNext.push({newx, newy});
          maze[newx][newy] = '+';
        }
      }

      swap(q, qNext);
    }

    return -1;
  }
};
