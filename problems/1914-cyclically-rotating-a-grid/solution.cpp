/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/cyclically-rotating-a-grid/
 * Runtime: 14ms (57.35%)
 */

class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int layers = min(m, n) >> 1;

    vector<vector<pair<int, int>>> vecs(layers);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int layer = min(min(i, j), min(m - i - 1, n - j - 1));
        vecs[min(min(i, j), min(m - i - 1, n - j - 1))].push_back({i, j});
      }
    }

    auto order = [m, n](int layer, int i, int j) -> pair<int, int> {
      if (j == layer) {
        return {0, i};
      }
      if (i == m - 1 - layer) {
        return {1, j};
      }
      if (j == n - 1 - layer) {
        return {2, -i};
      }
      return {3, -j};
    };

    vector<vector<int>> res(m, vector<int>(n));
    for (auto&& [layer, vec] : vecs | views::enumerate) {
      ranges::sort(vec, {}, [&](const auto p) {
        return order(layer, p.first, p.second);
      });

      const int rot = k % vec.size();
      for (int i = 0; i < vec.size(); ++i) {
        auto p = vec[i];
        auto nextp = vec[(i + rot) % vec.size()];
        res[nextp.first][nextp.second] = grid[p.first][p.second];
      }
    }

    return res;
  }
};
