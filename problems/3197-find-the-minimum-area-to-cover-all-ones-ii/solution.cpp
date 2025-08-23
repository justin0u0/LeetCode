/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/
 * Runtime: 72ms (45.38%)
 */

class Solution {
private:
  const int INF = 1000;

  int minimumSumOf2Rect(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
    int res = INT_MAX;
    // 1. Split by vertical line
    for (int i = x1; i < x2; ++i) {
      res = min(res, minimumSumOf1Rect(grid, x1, y1, i, y2) + minimumSumOf1Rect(grid, i + 1, y1, x2, y2));
    }
    // 2. Split by horizontal line
    for (int i = y1; i < y2; ++i) {
      res = min(res, minimumSumOf1Rect(grid, x1, y1, x2, i) + minimumSumOf1Rect(grid, x1, i + 1, x2, y2));
    }
    return res;
  }

  int minimumSumOf1Rect(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
    int xmin = INT_MAX, xmax = 0;
    int ymin = INT_MAX, ymax = 0;
    bool ok = false;
    for (int i = y1; i <= y2; ++i) {
      for (int j = x1; j <= x2; ++j) {
        if (grid[i][j] == 1) {
          ymin = min(ymin, i);
          ymax = max(ymax, i);
          xmin = min(xmin, j);
          xmax = max(xmax, j);
          ok = true;
        }
      }
    }
    if (!ok) {
      return INF;
    }
    return (xmax - xmin + 1) * (ymax - ymin + 1);
  }
public:
  int minimumSum(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    int res = INT_MAX;

    // 1. Split by horizontal line
    for (int i = 0; i < n - 1; ++i) {
      res = min(res, minimumSumOf1Rect(grid, 0, 0, m - 1, i) + minimumSumOf2Rect(grid, 0, i + 1, m - 1, n - 1));
      res = min(res, minimumSumOf2Rect(grid, 0, 0, m - 1, i) + minimumSumOf1Rect(grid, 0, i + 1, m - 1, n - 1));
    }

    // 2. Split by vertical line
    for (int i = 0; i < m - 1; ++i) {
      res = min(res, minimumSumOf1Rect(grid, 0, 0, i, n - 1) + minimumSumOf2Rect(grid, i + 1, 0, m - 1, n - 1));
      res = min(res, minimumSumOf2Rect(grid, 0, 0, i, n - 1) + minimumSumOf1Rect(grid, i + 1, 0, m - 1, n - 1));
    }

    return res;
  }
};
