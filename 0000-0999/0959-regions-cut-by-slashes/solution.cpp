/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/regions-cut-by-slashes/
 * Runtime: 4ms (84.82%)
 */

class Solution {
private:
  const static int maxRegions = 30 * 30 * 4;

  // We split each grid into 4 regions and labeled them with ID from [X, X+3],
  // ordered by up, left, down, and right.
  enum class RegionOfGrid {
    Up = 0,
    Left = 1,
    Down = 2,
    Right = 3
  };

  inline int regionLabel(int n, int gridI, int gridJ, RegionOfGrid r) {
    return (gridI * n + gridJ) * 4 + static_cast<int>(r);
  }

  int pa[Solution::maxRegions];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return pa[x] = find(pa[x]);
  }

  void merge(int x, int y) {
    x = find(pa[x]);
    y = find(pa[y]);
    if (x != y) {
      pa[x] = y;
    }
  }
public:
  int regionsBySlashes(vector<string>& grid) {
    const int n = grid.size();
    const int m = n * n * 4;

    for (int i = 0; i < m; ++i) {
      pa[i] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != 0) {
          // merge the left region of the grid with the right region of the left grid
          merge(regionLabel(n, i, j, RegionOfGrid::Left),
            regionLabel(n, i, j - 1, RegionOfGrid::Right));
        }
        if (i != 0) {
          // merge the up region of the grid with the down region of the upper grid
          merge(regionLabel(n, i, j, RegionOfGrid::Up),
            regionLabel(n, i - 1, j, RegionOfGrid::Down));
        }

        switch (grid[i][j]) {
          case ' ':
            merge(regionLabel(n, i, j, RegionOfGrid::Up),
              regionLabel(n, i, j, RegionOfGrid::Left));
            merge(regionLabel(n, i, j, RegionOfGrid::Down),
              regionLabel(n, i, j, RegionOfGrid::Right));
            merge(regionLabel(n, i, j, RegionOfGrid::Up),
              regionLabel(n, i, j, RegionOfGrid::Right));
            merge(regionLabel(n, i, j, RegionOfGrid::Down),
              regionLabel(n, i, j, RegionOfGrid::Left));
            break;
          case '/':
            merge(regionLabel(n, i, j, RegionOfGrid::Up),
              regionLabel(n, i, j, RegionOfGrid::Left));
            merge(regionLabel(n, i, j, RegionOfGrid::Down),
              regionLabel(n, i, j, RegionOfGrid::Right));
            break;
          case '\\':
            merge(regionLabel(n, i, j, RegionOfGrid::Up),
              regionLabel(n, i, j, RegionOfGrid::Right));
            merge(regionLabel(n, i, j, RegionOfGrid::Down),
              regionLabel(n, i, j, RegionOfGrid::Left));
            break;
        }
      }
    }
    
    int regions = 0;
    for (int i = 0; i < m; ++i) {
      if (pa[i] == i) {
        ++regions;
      }
    }

    return regions;
  }
};
