/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/
 * Runtime: 1914ms (5.15%)
 */

class Solution {
private:
  const int INF = 100000;
public:
  int maxProfit(const int n, const vector<int>& present, const vector<int>& future, const vector<vector<int>>& hierarchy, const int budget) {
    vector<vector<int>> graph(n);
    for (const auto& edge : hierarchy) {
      graph[edge[0] - 1].emplace_back(edge[1] - 1);
    }

    /*
      dp(u, 0, x): maximum profits of subtree `u` with exact budget of `x` with no discount on buying `u`
      dp(u, 1, x): maximum profits of subtree `u` with exact budget of `x` with discount on buying `u`
    */
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));

    function<void(int)> dfs = [&](int u) {
      for (const int v : graph[u]) {
        dfs(v);
      }

      for (int discount = 0; discount < 2; ++discount) {
        // 1. skip `u`
        vector<int> skip(budget + 1, -INF);
        skip[0] = 0;

        for (const int v : graph[u]) {
          vector<int> next(budget + 1, 0);
          for (int i = 0; i <= budget; ++i) {
            for (int j = 0; i + j <= budget; ++j) {
              next[i + j] = max(next[i + j], skip[i] + dp[v][0][j]);
            }
          }
          skip = move(next);
        }

        // 2. buy `u`
        vector<int> buy(budget + 1, -INF);
        buy[0] = 0;
        for (const int v : graph[u]) {
          vector<int> next(budget + 1, 0);
          for (int i = 0; i <= budget; ++i) {
            for (int j = 0; i + j <= budget; ++j) {
              next[i + j] = max(next[i + j], buy[i] + dp[v][1][j]);
            }
          }
          buy = move(next);
        }

        const int price = discount ? present[u] / 2 : present[u];
        vector<int>& best = dp[u][discount];
        for (int i = 0; i <= budget; ++i) {
          best[i] = skip[i];
          if (i >= price) {
            best[i] = max(best[i], buy[i - price] + future[u] - price);
          }
        }
      }
    };
    dfs(0);

    return *max_element(dp[0][0].begin(), dp[0][0].end());
  }
};
