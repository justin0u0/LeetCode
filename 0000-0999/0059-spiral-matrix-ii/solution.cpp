/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/spiral-matrix-ii/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));

    int val = 0;
    int x = 0;
    int y = -1;
    int dir = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < n * n; ++i) {
      int newx = x + dx[dir];
      int newy = y + dy[dir];
      while (newx < 0 || newy < 0 || newx >= n || newy >= n || m[newx][newy]) {
        dir = (dir + 1) % 4;
        newx = x + dx[dir];
        newy = y + dy[dir];
      }
      m[newx][newy] = ++val;
      x = newx;
      y = newy;
    }

    return m;
  }
};
