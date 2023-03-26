/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-cycle-in-a-graph/
 * Runtime: 167ms (97.20%)
 */

class Solution {
private:
  int longest;
  int id;
  vector<int> vis;

  void dfs(int u, const vector<int>& edges) {
    vis[u] = id;
    ++id;

    int v = edges[u];
    if (v != -1) {
      if (vis[v] == -1) {
        dfs(v, edges);
      } else if (vis[v] != 0) {
        // revisiting a in-stack node forms a loop
        longest = max(longest, vis[u] - vis[v] + 1);
      }
    }

    vis[u] = 0; // zero means not in stack
  }
public:
  int longestCycle(vector<int>& edges) {
    vis.resize(edges.size(), -1);
    longest = -1;
    id = 1;

   for (int i = 0; i < edges.size(); ++i) {
     if (vis[i] == -1) {
       dfs(i, edges);
     }
   }

   return longest;
  }
};
