/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/snakes-and-ladders/
 * Runtime: 16ms (91.20%)
 */

class Solution {
private:
  inline pair<int, int> id2pos(int id, int n) {
    int x = (id - 1) / n;
    int y = (id - 1) % n;
    if (x & 1) {
      return pair{n - 1 - x, n - 1 - y};
    }
    return pair{n - 1 - x, y};
  }

  inline int pos2id(pair<int, int> pos, int n) {
    int x = n - 1 - pos.first;
    if (x & 1) {
      return x * n + n - pos.second;
    }
    return x * n + pos.second + 1;
  }
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    queue<pair<int, int>> q, qNext;
    q.push(pair{n - 1, 0});

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[n - 1][0] = true;

    for (int dist = 0; !q.empty(); ++dist) {
      int qs = q.size();
      while (qs--) {
        pair<int, int> u = q.front();
        q.pop();
        int id = pos2id(u, n);

        if (id == n * n) {
          return dist;
        }
        for (int i = id + 1; i <= min(id + 6, n * n); ++i) {
          pair<int, int> v = id2pos(i, n);
          int b = board[v.first][v.second];
          if (b != -1) {
            v = id2pos(b, n);
          }

          if (vis[v.first][v.second]) {
            continue;
          }

          vis[v.first][v.second] = true;
          qNext.push(v);
        }
      }
      swap(q, qNext);
    }

    return -1;
  }
};
