/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-ii/
 * Runtime: 11ms (91.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int n;
  int sum[101];
  int dp[101][101][2];

  int dfs(int p, int m, bool alice) {
    if (dp[p][m][alice] != -1) {
      return dp[p][m][alice];
    }
    if (p == n) {
      return 0;
    }

    int& res = dp[p][m][alice];

    if (alice) {
      res = 0;
      for (int x = 1; x <= 2 * m; ++x) {
        int last = x + p;
        if (last > n) {
          break;
        }
        res = max(res, dfs(last, max(m, x), !alice) + sum[last] - sum[p]);
      }
    } else {
      res = 0x3f3f3f3f;
      for (int x = 1; x <= 2 * m; ++x) {
        int last = x + p;
        if (last > n) {
          break;
        }
        res = min(res, dfs(last, max(m, x), !alice));
      }
    }

    return res;
  }
public:
  int stoneGameII(vector<int>& piles) {
    memset(dp, -1, sizeof(dp));

    n = piles.size();
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + piles[i - 1];
    }

    return dfs(0, 1, true);
  }
};
