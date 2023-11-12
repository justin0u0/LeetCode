/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bus-routes/
 * Runtime: 121ms (99.21%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Node {
    int r;
    int d;

    bool operator<(const Node& rhs) const {
      return d > rhs.d;
    }
  };
public:
  int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
    if (source == target) {
      return 0;
    }

    const int n = routes.size();
    unordered_set<int> targets;
    priority_queue<Node> pq;
    vector<int> dist(n, 0x3f3f3f3f);
    unordered_map<int, vector<int>> stops;
    for (int i = 0; i < n; ++i) {
      for (int s : routes[i]) {
        if (s == source) {
          pq.push({i, 1});
          dist[i] = 1;
        } else if (s == target) {
          targets.emplace(i);
        }
        stops[s].emplace_back(i);
      }
    }

    while (!pq.empty()) {
      Node u = pq.top();
      pq.pop();

      if (targets.find(u.r) != targets.end()) {
        return u.d;
      }

      if (dist[u.r] < u.d) {
        continue;
      }

      for (int s : routes[u.r]) {
        for (int r : stops[s]) {
          if (dist[r] > u.d + 1) {
            dist[r] = u.d + 1;
            pq.push({r, u.d + 1});
          }
        }
        stops[s].clear();
      }
    }

    return -1;
  }
};
