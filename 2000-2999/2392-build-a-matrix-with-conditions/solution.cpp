/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/build-a-matrix-with-conditions/
 * Runtime: 75ms (99.44%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  vector<int> vis;
  vector<int> inq;

  bool dfs(int u, const vector<vector<int>>& graph, vector<int>& result) {
    vis[u] = true;
    inq[u] = true;
    for (int v : graph[u]) {
      if (inq[v]) {
        return false;
      }
      if (!vis[v] && !dfs(v, graph, result)) {
        return false;
      }
    }
    inq[u] = false;
    result.emplace_back(u);
    return true;
  }

  bool topologySort(const int n, const vector<vector<int>>& conditions, vector<int>& result) {
    vector<vector<int>> graph(n + 1);
    for (const auto& cond : conditions) {
      graph[cond[0]].emplace_back(cond[1]);
    }

    vis.resize(n + 1);
    fill(vis.begin(), vis.end(), false);
    inq.resize(n + 1);
    fill(inq.begin(), inq.end(), false);

    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && !dfs(i, graph, result)) {
        return false;
      }
    }

    reverse(result.begin(), result.end());
    return true;
  }
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rows;
    rows.reserve(k);
    if (!topologySort(k, rowConditions, rows)) {
      return {};
    }

    vector<int> cols;
    cols.reserve(k);
    if (!topologySort(k, colConditions, cols)) {
      return {};
    }

    vector<vector<int>> mat(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (rows[i] == cols[j]) {
          mat[i][j] = rows[i];
        }
      }
    }
    return mat;
  }
};
