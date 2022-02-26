/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
 * Runtime: 12ms
 */

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = (int)graph.size();
    const int m = (1 << n);

    if (n == 1) {
      return 0;
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>>* q = new queue<pair<int, int>>;
    for (int i = 0; i < n; ++i) {
      q->push({i, 0});
      vis[i][0] = true;
    }

    queue<pair<int, int>>* q2 = new queue<pair<int, int>>;

    for (int answer = 0; ; ++answer) {
      while (!q->empty()) {
        pair<int, int> p = q->front();
        q->pop();

        if (p.second == m - 1) {
          delete q;
          delete q2;
  
          return answer - 1;
        }

        for (int v : graph[p.first]) {
          int state = p.second | (1 << v);
          if (!vis[v][state]) {
            vis[v][state] = true;
            q2->push({v, state});
          }
        }
      }

      swap(q, q2);
    }

    delete q;
    delete q2;

    return 0;
  }
};

