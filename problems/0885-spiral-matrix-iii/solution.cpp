/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/spiral-matrix-iii/
 * Runtime: 5ms (88.41%)
 */

class Solution {
private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};
public:
  vector<vector<int>> spiralMatrixIII(const int rows, const int cols, const int rStart, const int cStart) {
    int x = rStart;
    int y = cStart;
    int dir = 0;
    int d = 1;

    const int n = rows * cols;
    vector<vector<int>> answer;
    answer.reserve(n);
    answer.emplace_back(vector<int>{x, y});

    while (answer.size() < n) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < d; ++j) {
          x += dx[dir];
          y += dy[dir];
          if (x >= 0 && x < rows && y >= 0 && y < cols) {
            answer.emplace_back(vector<int>{x, y});
          }
        }
        dir = (dir + 1) % 4;
      }
      ++d;
    }
    
    return answer;
  }
};
