/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/detonate-the-maximum-bombs/
 * Runtime: 94ms (87.11%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;  
}();

class Solution {
private:
  vector<int> graph[101];
  vector<bool> vis;

  int dfs(int u) {
    int sum = 1;
    for (const int v : graph[u]) {
      if (!vis[v]) {
        vis[v] = true;
        sum += dfs(v);
      }
    }
    return sum;
  }
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    for (int i = 0; i < n; ++i) {
      graph[i].clear();
    }

    for (int i = 0; i < n; ++i) {
      vector<int>& bi = bombs[i];
      for (int j = i + 1; j < n; ++j) {
        vector<int>& bj = bombs[j];
        long long dist = (long long)(bi[0] - bj[0]) * (bi[0] - bj[0])
          + (long long)(bi[1] - bj[1]) * (bi[1] - bj[1]);
        if (dist <= (long long)bi[2] * bi[2]) {
          graph[i].emplace_back(j);
        }
        if (dist <= (long long)bj[2] * bj[2]) {
          graph[j].emplace_back(i);
        }
      }
    }

    vis.resize(n);

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      fill(vis.begin(), vis.end(), false);

      vis[i] = true;
      answer = max(answer, dfs(i));
    }
    return answer;
  }
};
