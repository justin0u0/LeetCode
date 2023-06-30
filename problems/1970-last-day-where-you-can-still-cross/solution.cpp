/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/last-day-where-you-can-still-cross/
 * Runtime: 277ms (99.10%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int pa[20005];

  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }

  inline void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      pa[fx] = fy;
    }
  }
public:
  int latestDayToCross(int row, int col, const vector<vector<int>>& cells) {
    vector<vector<int>> grid(row, vector<int>(col, -1));

    int n = cells.size();

    const int l = n;
    const int r = n + 1;

    for (int i = 0; i <= n + 1; ++i) {
      pa[i] = i;
    }

    for (int i = 0; i < n; ++i) {
      const auto& cell = cells[i];
      const int x = cell[0] - 1;
      const int y = cell[1] - 1;

      grid[x][y] = i;

      if (y == 0) {
        merge(i, l);
      }
      if (y == col - 1) {
        merge(i, r);
      }

      for (int j = 0; j < 8; ++j) {
        const int newx = x + dx[j];
        const int newy = y + dy[j];
        if (newx < 0 || newy < 0 || newx >= row || newy >= col || grid[newx][newy] == -1) {
          continue;
        }

        merge(i, grid[newx][newy]);
      }

      if (find(l) == find(r)) {
        return i;
      }
    }

    return n;
  }
};

