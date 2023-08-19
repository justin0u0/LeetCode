/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
 * Runtime: 11ms (100.00%)
 */

class Solution {
private:
  typedef vector<int> VI;
  typedef vector<VI> VVI;
  typedef pair<int, int> PII;
  typedef vector<PII> VPII;
  typedef vector<VPII> VVPII;

  class DJS {
  private:
    VI pa;
  public:
    DJS(int n) : pa(n) {
      for (int i = 0; i < n; ++i) {
        pa[i] = i;
      }
    }

    int find(int x) {
      if (pa[x] == x) {
        return x;
      }
      return (pa[x] = find(pa[x]));
    }

    void merge(int x, int y) {
      x = find(x);
      y = find(y);
      pa[x] = y;
    }
  };

  enum EdgeType {
    NON_MST,
    MST_CRITICAL,
    MST_NON_CRITICAL
  };

  class LCA {
  private:
    VVI& edges;
    VPII pa;
    VI depth;
    VVPII graph;

    void dfs(int u, int p, int e, int d) {
      depth[u] = d;
      pa[u] = {p, e};
      for (const auto [v, pe] : graph[u]) {
        if (v != p) {
          dfs(v, u, pe, d + 1);
        }
      }
    }
  public:
    LCA(int n, VVI& edges) : edges(edges), pa(n), depth(n), graph(n) {
      for (int i = 0; i < edges.size(); ++i) {
        const auto& e = edges[i];
        if (e[4] == EdgeType::MST_CRITICAL) {
          graph[e[0]].emplace_back(e[1], i);
          graph[e[1]].emplace_back(e[0], i);
        }
      }
      dfs(0, -1, -1, 0);
    }

    bool markNonCriticalEdges(int u, int v, int cost) {
      vector<int> candidates;
      int maxCost = 0;

      if (depth[u] < depth[v]) {
        swap(u, v);
      }
      while (depth[u] != depth[v]) {
        auto [p, e] = pa[u];
        maxCost = max(maxCost, edges[e][2]);
        candidates.emplace_back(e);
        u = p;
      }
      while (u != v) {
        auto [pu, eu] = pa[u];
        auto [pv, ev] = pa[v];
        maxCost = max(maxCost, max(edges[eu][2], edges[ev][2]));
        candidates.emplace_back(eu);
        candidates.emplace_back(ev);
        u = pu;
        v = pv;
      }

      if (maxCost < cost) {
        return false;
      }
      for (const int e : candidates) {
        if (edges[e][2] == cost) {
          edges[e][4] = EdgeType::MST_NON_CRITICAL;
        }
      }
      return true;
    }
  };
public:
  VVI findCriticalAndPseudoCriticalEdges(int n, VVI& edges) {
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].emplace_back(i);
    }
    sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[2] < rhs[2];
    });

    DJS djs(n);
    for (int i = 0; i < edges.size(); ++i) {
      auto& e = edges[i];
      int x = djs.find(e[0]);
      int y = djs.find(e[1]);
      if (x != y) {
        djs.merge(x, y);
        e.emplace_back(EdgeType::MST_CRITICAL);
      } else {
        e.emplace_back(EdgeType::NON_MST);
      }
    }

    LCA lca(n, edges);
    for (int i = 0; i < edges.size(); ++i) {
      auto& e = edges[i];
      if (e[4] != EdgeType::NON_MST) {
        continue;
      }

      if (lca.markNonCriticalEdges(e[0], e[1], e[2])) {
        e[4] = EdgeType::MST_NON_CRITICAL;
      }
    }

    VVI answer(2);
    for (int i = 0; i < edges.size(); ++i) {
      const auto ei = edges[i][3];
      const auto et = edges[i][4];
      if (et == EdgeType::MST_CRITICAL) {
        answer[0].emplace_back(ei);
      } else if (et == EdgeType::MST_NON_CRITICAL) {
        answer[1].emplace_back(ei);
      }
    }
    return answer;
  }
};
