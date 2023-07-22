/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/knight-probability-in-chessboard/
 * Runtime: 7ms (94.43%)
 */

class Solution {
private:
  int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> pre(n, vector<double>(n, 0));
    vector<vector<double>> cur(n, vector<double>(n, 0));

    pre[row][column] = 1.0;

    while (k--) {
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
          cur[x][y] = 0;
        }
      }

      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
          if (pre[x][y] == 0) {
            continue;
          }
          for (int i = 0; i < 8; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newy < 0 || newx >= n || newy >= n) {
              continue;
            }

            cur[newx][newy] += pre[x][y] * 0.125;
          }
        }
      }
      swap(pre, cur);
    }

    double answer = 0;
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        answer += pre[x][y];
      }
    }
    return answer;
  }
};
