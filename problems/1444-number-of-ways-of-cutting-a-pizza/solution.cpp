/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
 * Runtime: 11ms (96.70%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
  int dp[55][55][15];
  int rows, cols;
  int sum[55][55];

  int dfs(const vector<string>& pizza, int n, int m, int k) {
    if (dp[n][m][k] != -1) {
      return dp[n][m][k];
    }

    if (k == 1) {
      return (dp[n][m][k] = sum[rows][cols] - sum[n][cols] - sum[rows][m] + sum[n][m] > 0);
    }

    long long total = 0;
    for (int i = n + 1; i < rows; ++i) {
      if (sum[i][cols] - sum[i][m] - sum[n][cols] + sum[n][m] > 0) {
        total += dfs(pizza, i, m, k - 1);
      }
    }
    for (int j = m + 1; j < cols; ++j) {
      if (sum[rows][j] - sum[n][j] - sum[rows][m] + sum[n][m] > 0) {
        total += dfs(pizza, n, j, k - 1);
      }
    }

    return (dp[n][m][k] = total % mod);
  }
public:
  int ways(const vector<string>& pizza, int k) {
    memset(dp, -1, sizeof(dp));
    rows = pizza.size();
    cols = pizza[0].size();

    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + (pizza[i][j] == 'A');
      }
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        sum[i + 1][j + 1] += sum[i][j + 1];
      }
    }

    return dfs(pizza, 0, 0, k);
  }
};

