/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/spiral-matrix/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int x = 0;
    int y = 0;
    int d = 0;
    vector<int> answer(n * m);
    for (int i = 0; i < n * m; ++i) {
      answer[i] = matrix[x][y];
      matrix[x][y] = INT_MIN;
      int newx = x + dx[d];
      int newy = y + dy[d];
      if (newx < 0 || newy < 0 || newx >= n || newy >= m || matrix[newx][newy] == INT_MIN) {
        d = (d + 1) % 4;
        x = x + dx[d];
        y = y + dy[d];
      } else {
        x = newx;
        y = newy;
      }
    }
    return answer;
  }
};
