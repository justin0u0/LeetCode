/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/jump-game-iv/
 * Runtime: 220ms
 */

class Solution {
public:
  int minJumps(vector<int>& arr) {
    int n = (int)arr.size();

    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
      m[arr[i]].emplace_back(i);
    }

    vector<bool> visit(n, false);

    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0] = true;

    while (true) {
      pair<int, int> u = q.front();
      q.pop();

      if (u.first == n - 1) {
        return u.second;
      }

      if (u.first != 0 && !visit[u.first - 1]) {
        visit[u.first - 1] = true;
        q.push({u.first - 1, u.second + 1});
      }
      if (u.first != n - 1 && !visit[u.first + 1]) {
        visit[u.first + 1] = true;
        q.push({u.first + 1, u.second + 1});
      }

      int val = arr[u.first];
      if (m.find(val) != m.end()) {
        for (int i : m.at(val)) {
          if (!visit[i]) {
            visit[i] = true;
            q.push({i, u.second + 1});
          }
        }
        m.erase(val);
      }
    }

    // should never happens
    return false;
  }
};
