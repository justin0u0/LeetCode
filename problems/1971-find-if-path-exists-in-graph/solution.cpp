/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-if-path-exists-in-graph/
 * Runtime: 632ms (92.22%)
 */

class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (n == 1) {
      return true;
    }

    vector<vector<int>> graph(n);
    for (const vector<int>& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    queue<int> q1, q1Next;
    q1.push(source);
    queue<int> q2, q2Next;
    q2.push(destination);

    vector<bool> vis1(n, false);
    vis1[source] = true;
    vector<bool> vis2(n, false);
    vis2[destination] = true;

    while (!q1.empty() || !q2.empty()) {
      while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        for (const int& v : graph[u]) {
          if (vis2[v]) {
            return true;
          }
          if (!vis1[v]) {
            vis1[v] = true;
            q1Next.push(v);
          }
        }
      }
      while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        for (const int& v : graph[u]) {
          if (vis1[v]) {
            return true;
          }
          if (!vis2[v]) {
            vis2[v] = true;
            q2Next.push(v);
          }
        }
      }
      swap(q1, q1Next);
      swap(q2, q2Next);
    }
    return false;
  }
};

