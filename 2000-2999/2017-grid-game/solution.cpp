/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/grid-game/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long gridGame(const vector<vector<int>>& grid) {
    long long u = accumulate(grid[0].begin() + 1, grid[0].end(), 0LL);
    long long d = 0;

    long long mn = u;
    for (int i = 1; i < grid[0].size(); ++i) {
      u -= grid[0][i];
      d += grid[1][i - 1];
      mn = min(mn, max(u, d));
    }
    return mn;
  }
};
