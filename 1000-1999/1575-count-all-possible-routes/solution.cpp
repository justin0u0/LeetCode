/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-all-possible-routes/
 * Runtime: 427ms (14.64%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int mod = 1e9 + 7;

  int dp[201][100];
public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    memset(dp, 0, sizeof dp);
    dp[0][start] = 1;

    int n = locations.size();
    int answer = 0;
    for (int k = 0; k < fuel; ++k) {
      answer = (answer + dp[k][finish]) % mod;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == j) {
            continue;
          }

          int dist = abs(locations[i] - locations[j]);
          if (k + dist > fuel) {
            continue;
          }

          int& d = dp[k + dist][j];
          d = (d + dp[k][i]) % mod;
        }
      }
    }

    return (answer + dp[fuel][finish]) % mod;
  }
};
