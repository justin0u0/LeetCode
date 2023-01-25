/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
 * Runtime: 180ms (85.32%)
 */

class Solution {
private:
  class BFS {
  private:
    const vector<int>& edges;
  public:
    BFS(const vector<int>& edges) : edges(edges) {}

    void bfs(int s, vector<int>& dist) {
      queue<int> q;
      q.push(s);
      dist[s] = 0;

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        int v = edges[u];
        if (v == -1 || dist[v] != -1) {
          continue;
        }

        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  };
public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    if (node1 == node2) {
      return node1;
    }

    int n = edges.size();
    BFS b(edges);
    vector<int> dist1(n, -1);
    b.bfs(node1, dist1);
    vector<int> dist2(n, -1);
    b.bfs(node2, dist2);

    int minVal = INT_MAX;
    int answer = -1;
    for (int i = 0; i < n; ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minVal) {
          minVal = maxDist;
          answer = i;
        }
      }
    }

    return answer;
  }
};
