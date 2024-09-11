/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-ii/
 * Runtime: 11ms (91.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int dp[101][101];
public:
  int stoneGameII(vector<int>& piles) {
    // dp[i][j]: maximum difference of stones the first player get
    // with the from the ith tiles and M = j.

    const int n = piles.size();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = INT_MIN;
      }
    }

    function<int(int, int)> dfs = [&](int x, int m) {
      if (x == n) {
        return 0;
      }

      if (dp[x][m] != INT_MIN) {
        return dp[x][m];
      }

      int& best = dp[x][m];
      int take = 0;

      // Try to take 1 ~ 2M stones
      for (int i = x; i < min(n, x + 2 * m); ++i) {
        take += piles[i];
        best = max(best, take - dfs(i + 1, min(n, max(m, i - x + 1))));
      }

      return best;
    };

    int total = accumulate(piles.begin(), piles.end(), 0);
    return (total + dfs(0, 1)) / 2;
  }
};
