/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/where-will-the-ball-fall/
 * Runtime: 24ms (94.95%)
 */

class Solution {
public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> answer(m);
    for (int i = 0; i < m; ++i) {
      int& col = answer[i];
      col = i;

      for (int j = 0; j < n; ++j) {
        bool left = (grid[j][col] == -1);

        if (left && (col == 0 || grid[j][col - 1] == 1)) {
          col = -1;
          break;
        }

        if (!left && (col == m - 1 || grid[j][col + 1] == -1)) {
          col = -1;
          break;
        }

        if (left) {
          --col;
        } else {
          ++col;
        }
      }
    }

    return answer;
  }
};
