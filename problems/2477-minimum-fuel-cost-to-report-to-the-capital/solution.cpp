/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
 * Runtime: 590ms (85.75%)
 */

class Solution {
private:
  class Solver {
  private:
    int n;
    int seats;
    const vector<vector<int>>& graph;
  public:
    Solver(int n, int seats, const vector<vector<int>>& graph) : n(n), seats(seats), graph(graph) {}

    pair<long long, int> dfs(int u, int fa) {
      long long cost = 0;
      int childs = 1;
      for (const int& v : graph[u]) {
        if (v != fa) {
          auto [vCost, vChilds] = dfs(v, u);
          cost += vCost;
          childs += vChilds;
        }
      }
      if (fa != -1) {
        cost += (childs - 1) / seats + 1;
      }
      return {cost, childs};
    }
  };
public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size() + 1;
    vector<vector<int>> graph(n);
    for (const vector<int>& e : roads) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    Solver s(n, seats, graph);
    return s.dfs(0, -1).first;
  }
};
