/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
 * Runtime: 1128ms (10.25%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumInvitations(vector<int>& favorite) {
    const int n = favorite.size();

    vector<int> vis(n, 0);
    vector<int> dp(n, 0);
    vector<int> pa(n, -1);
    vector<bool> stacked(n, false);
    int dfsn = 0;
    int mx = 0;

    function<void(int)> dfs = [&](int u) {
      vis[u] = ++dfsn;
      stacked[u] = true;

      const int v = favorite[u];
      if (vis[v] == 0) {
        dfs(v);
      }

      if (stacked[v] && favorite[v] == u) {
        dp[u] = 1;
        dp[v] = 1;
        pa[u] = u;
        pa[v] = v;
      } else if (stacked[v]) {
        mx = max(mx, dfsn - vis[v] + 1);
      } else if (dp[u] == 0 && dp[v] != 0) {
        dp[u] = dp[v] + 1;
      }

      if (pa[u] == -1) {
        pa[u] = pa[v];
      }
  
      stacked[u] = false;
    };

    for (int i = 0; i < n; ++i) {
      if (vis[i] == 0) {
        dfs(i);
      }
    }

    for (int i = 0; i < n; ++i) {
      const int p = pa[i];
      if (p != -1) {
        dp[p] = max(dp[p], dp[i]);
      }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      const int j = favorite[i];
      if (i < j && favorite[j] == i) {
        sum += dp[i] + dp[j];
      }
    }

    return max(mx, sum);
  }
};
