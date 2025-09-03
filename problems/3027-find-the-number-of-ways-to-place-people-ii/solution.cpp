/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/
 * Runtime: 501ms (8.51%)
 */

class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    vector<int> xv;
    vector<int> yv;
    for (const auto& p : points) {
      xv.emplace_back(p[0]);
      yv.emplace_back(p[1]);
    }

    sort(xv.begin(), xv.end());
    xv.resize(unique(xv.begin(), xv.end()) - xv.begin());
    sort(yv.begin(), yv.end());
    yv.resize(unique(yv.begin(), yv.end()) - yv.begin());

    auto discretize = [&](int x, int y) -> pair<int, int> {
      return {
        lower_bound(xv.begin(), xv.end(), x) - xv.begin() + 1,
        lower_bound(yv.begin(), yv.end(), y) - yv.begin() + 1
      };
    };

    const int n = xv.size();
    const int m = yv.size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (auto& p : points) {
      const auto [x, y] = discretize(p[0], p[1]);
      p[0] = x;
      p[1] = y;
      sum[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }

    const int k = points.size();
    int res = 0;
    for (int i = 0; i < k; ++i) {
      const int x1 = points[i][0];
      const int y1 = points[i][1];
      for (int j = 0; j < k; ++j) {
        const int x2 = points[j][0];
        const int y2 = points[j][1];
        if (i == j || x1 > x2 || y1 < y2) {
          continue;
        }
        if (sum[x2][y1] - sum[x1 - 1][y1] - sum[x2][y2 - 1] + sum[x1 - 1][y2 - 1] == 2) {
          ++res;
        }
      }
    }
    return res;
  }
};
