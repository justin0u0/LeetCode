/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
 * Runtime: 1629ms (20.41%)
 */

class Solution {
public:
  int minMoves(const vector<string>& classroom, const int energy) {
    const auto m = classroom.size();
    const auto n = classroom[0].size();

    int sx, sy;
    int lcnt = 0;
    vector<vector<int>> lid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (classroom[i][j] == 'S') {
          sx = i;
          sy = j;
        } else if (classroom[i][j] == 'L') {
          lid[i][j] = lcnt++;
        }
      }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, energy, 0});

    using VB = vector<bool>;
    using VB2 = vector<VB>;
    using VB3 = vector<VB2>;
    using VB4 = vector<VB3>;

    VB4 vis(m, VB3(n, VB2(energy + 1, VB(1 << lcnt, false))));
    vis[sx][sy][energy][0] = true;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    for (int dist = 0; !q.empty(); ++dist) {
      auto size = q.size();
      while (size--) {
        const auto [x, y, e, l] = q.front();
        q.pop();

        if (l == (1 << lcnt) - 1) {
          return dist;
        }

        for (int i = 0; i < 4; ++i) {
          const auto x2 = x + dx[i];
          const auto y2 = y + dy[i];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || classroom[x2][y2] == 'X') {
            continue;
          }
  
          const auto e2 = (classroom[x][y] == 'R') ? energy - 1 : e - 1;
          const auto l2 = (classroom[x2][y2] == 'L') ? l | (1 << lid[x2][y2]) : l;
          if (e2 < 0 || vis[x2][y2][e2][l2]) {
            continue;
          }

          q.push({x2, y2, e2, l2});
          vis[x2][y2][e2][l2] = true;
        }
      }
    }

    return -1;
  }
};
