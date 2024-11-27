/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/
 * Runtime: 16ms (96.43%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> dist(n);
    for (int i = 0; i < n; ++i) {
      dist[i] = i;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
      graph[i].emplace_back(i + 1);
    }
    queue<int> q;

    vector<int> answer;
    answer.reserve(queries.size());

    for (const auto& query : queries) {
      graph[query[0]].emplace_back(query[1]);
      q.push(query[0]);

      while (!q.empty()) {
        const int u = q.front();
        q.pop();

        for (const int v : graph[u]) {
          if (dist[v] > dist[u] + 1) {
            q.push(v);
            dist[v] = dist[u] + 1;
          }
        }
      }

      answer.emplace_back(dist.back());
    }

    return answer;
  }
};
