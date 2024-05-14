/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-with-maximum-gold/
 * Runtime: 76ms (97.10%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int sumAllNonZeros(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0) {
          sum += grid[i][j];
        } else {
          return 0;
        }
      }
    }
    return sum;
  }
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    int sum = sumAllNonZeros(grid);
    if (sum != 0) {
      return sum;
    }

    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};
    function<int(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
        return 0;
      }
      const int g = grid[i][j];
      grid[i][j] = 0;
      const int d = g + max(
        max(dfs(i + 1, j), dfs(i - 1, j)),
        max(dfs(i, j + 1), dfs(i, j - 1))
      );
      grid[i][j] = g;
      return d;
    };

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0) {
          answer = max(answer, dfs(i, j));
        }
      }
    }
    return answer;
  }
};
