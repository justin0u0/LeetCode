/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * Runtime: 57ms (13.31%)
 */

class Solution {
private:
  struct Offset {
    int di;
    int dj;
    bitset<6> valid;
  };

  // left, up, right, down
  static constexpr array<Offset, 4> offsets{{
    {0, -1, 0b101001},
    {-1, 0, 0b001110},
    {0, 1, 0b010101},
    {1, 0, 0b110010}
  }};
  static constexpr array<array<int, 2>, 6> validOffsets{{
    {0, 2}, {1, 3}, {0, 3}, {2, 3}, {0, 1}, {1, 2}
  }};
public:
  bool hasValidPath(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<int> pa(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        pa[i * n + j] = i * n + j;
      }
    }

    auto find = [&](this auto&& self, int x) {
      if (pa[x] == x) {
        return x;
      }
      return (pa[x] = self(pa[x]));
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (const auto k : validOffsets[grid[i][j] - 1]) {
          const auto& [di, dj, valid] = offsets[k];
          const int i2 = i + di;
          const int j2 = j + dj;
          if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n || !valid.test(grid[i2][j2] - 1)) {
            continue;
          }

          const int f1 = find(i * n + j);
          const int f2 = find(i2 * n + j2);
          if (f1 != f2) {
            pa[f1] = f2;
          }
        }
      }
    }

    return find(0) == find(m * n - 1);
  }
};
