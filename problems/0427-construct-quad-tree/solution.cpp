/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-quad-tree/
 * Runtime: 11ms (93.84%)
 */

class Solution {
private:
  inline int equal(const vector<vector<int>>& grid, int x, int y, int d) {
    int val = grid[x][y];
    for (int i = x; i < x + d; ++i) {
      for (int j = y; j < y + d; ++j) {
        if (grid[i][j] != val) {
          return -1;
        }
      }
    }
    return val;
  }

  Node* build(const vector<vector<int>>& grid, int x, int y, int d) {
    int e = equal(grid, x, y, d);
    if (e != -1) {
      return new Node(e, true);
    }

    int hd = d / 2;
    Node* tl = build(grid, x, y, hd);
    Node* tr = build(grid, x, y + hd, hd);
    Node* bl = build(grid, x + hd, y, hd);
    Node* br = build(grid, x + hd, y + hd, hd);
    return new Node(0, false, tl, tr, bl, br);
  }
public:
  Node* construct(const vector<vector<int>>& grid) {
    return build(grid, 0, 0, grid.size());
  }
};

