/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/open-the-lock/
 * Runtime: 163ms (51.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  bool vis[10][10][10][10];
  bool dead[10][10][10][10];
public:
  int openLock(const vector<string>& deadends, const string& target) {
    memset(vis, 0, sizeof(vis));
    memset(dead, 0, sizeof(dead));

    for (const auto& s : deadends) {
      if (s == "0000") {
        return -1;
      }
      dead[s[0] - '0'][s[1] - '0'][s[2] - '0'][s[3] - '0'] = true;
    }

    const vector<int> end = {
      target[0] - '0',
      target[1] - '0',
      target[2] - '0',
      target[3] - '0'
    };

    queue<vector<int>> q;
    q.push(vector<int>{0, 0, 0, 0});
    vis[0][0][0][0] = true;
    for (int dist = 0; !q.empty(); ++dist) {
      int sz = q.size();
      while (sz--) {
        auto u = q.front();
        q.pop();
  
        if (u == end) {
          return dist;
        }
  
        for (int i = 0; i < 4; ++i) {
          vector<int> v = u;
          v[i] = (v[i] + 1) % 10;
          if (!vis[v[0]][v[1]][v[2]][v[3]] && !dead[v[0]][v[1]][v[2]][v[3]]) {
            vis[v[0]][v[1]][v[2]][v[3]] = true;
            q.push(v);
          }

          v = u;
          v[i] = (v[i] + 9) % 10;
          if (!vis[v[0]][v[1]][v[2]][v[3]] && !dead[v[0]][v[1]][v[2]][v[3]]) {
            vis[v[0]][v[1]][v[2]][v[3]] = true;
            q.push(v);
          }
        }
      }
    }
    return -1;
  }
};
