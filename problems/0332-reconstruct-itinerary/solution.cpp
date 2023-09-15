/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reconstruct-itinerary/
 * Runtime: 21ms (59.65%)
 */

class Solution {
private:
  map<string, multiset<string>> edges;
  vector<string> routes;

  void dfs(string u) {
    while (!edges[u].empty()) {
      auto it = edges[u].begin();
      auto v = *it;
      edges[u].erase(it);
      dfs(v);
    }
    routes.emplace_back(u);
  }
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    routes.clear();
    for (const auto& t : tickets) {
      edges[t[0]].emplace(t[1]);
    }
    dfs("JFK");
    reverse(routes.begin(), routes.end());
    return routes;
  }
};
