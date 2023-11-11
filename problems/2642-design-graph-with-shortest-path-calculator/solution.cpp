/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
 * Runtime: 127ms (99.16%)
 */

class Graph {
private:
  vector<vector<pair<int, int>>> graph;
  vector<int> dist;
public:
  Graph(int n, vector<vector<int>>& edges) : graph(n), dist(n) {
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(pair{e[1], e[2]});
    }
  }
  
  void addEdge(vector<int> e) {
    graph[e[0]].emplace_back(pair{e[1], e[2]});
  }

  int shortestPath(int s, int t) {
    fill(dist.begin(), dist.end(), 0x3f3f3f3f);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [du, u] = pq.top();
      pq.pop();

      if (u == t) {
        return du;
      }

      if (du > dist[u]) {
        continue;
      }

      for (auto [v, dv] : graph[u]) {
        if (dist[v] > du + dv) {
          dist[v] = du + dv;
          pq.push({dist[v], v});
        }
      }
    }

    return -1;
  }
};
