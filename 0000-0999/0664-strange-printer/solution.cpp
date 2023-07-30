/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/strange-printer/
 * Runtime: 271ms (14.92%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
#define INF 0x3f3f3f3f
private:
  int dp[101][101][128];

  int solve(const string& s, int i, int j, char c) {
    if (i > j) {
      return 0;
    }

    int& d = dp[i][j][c];
    if (d != INF) {
      return d;
    }
    if (s[i] == c) {
      d = solve(s, i + 1, j, c);
      return d;
    }
    if (s[j] == c) {
      d = solve(s, i, j - 1, c);
      return d;
    }

    for (int k = i; k <= j; ++k) {
      if (s[i] == s[k]) {
        d = min(d, solve(s, i, k, s[i]) + solve(s, k + 1, j, c) + 1);
      }
      if (s[j] == s[k]) {
        d = min(d, solve(s, i, k - 1, c) + solve(s, k, j, s[j]) + 1);
      }
    }
    return d;
  }
public:
  int strangePrinter(const string& s) {
    memset(dp, INF, sizeof(dp));
    return solve(s, 0, s.length() - 1, 0);
  }
};
