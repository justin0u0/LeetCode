/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-with-minimum-effort/
 * Runtime: 145ms
 * Time Complexity: O(NMlog(NM))
 * Description: Variant of Dijkstra
 */

class Solution {
private:
  class Node {
  public:
    int dist;
    int x;
    int y;

    bool operator < (const Node& rhs) const {
      return dist > rhs.dist;
    }
  };
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    const int INF = 0x3f3f3f3f;
    int n = (int)heights.size();
    int m = (int)heights[0].size();
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vector<vector<int>> d(n, vector<int>(m, INF));
    d[0][0] = 0;
    priority_queue<Node> pq;
    pq.emplace(Node{0, 0, 0});

    while (!pq.empty()) {
      Node u = pq.top();
      pq.pop();

      if (u.x == n - 1 && u.y == m - 1) {
        return u.dist;
      }

      if (d[u.x][u.y] < u.dist) {
        continue;
      }

      for (int i = 0; i < 4; ++i) {
        int nx = u.x + dx[i];
        int ny = u.y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
          continue;
        }

        int dist = abs(heights[u.x][u.y] - heights[nx][ny]);
        if (d[nx][ny] > max(d[u.x][u.y], dist)) {
          d[nx][ny] = max(d[u.x][u.y], dist);
          pq.emplace(Node{d[nx][ny], nx, ny});
        }
      }
    }

    return INF;
  }
};
