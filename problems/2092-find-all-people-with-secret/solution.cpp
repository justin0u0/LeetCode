/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-people-with-secret/
 * Runtime: 679ms (38.94%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<bool> got(n, false);
    got[0] = true;
    got[firstPerson] = true;

    sort(meetings.begin(), meetings.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[2] < rhs[2];
    });

    for (int i = 0; i < meetings.size(); ) {
      const int time = meetings[i][2];

      unordered_map<int, int> m;
      unordered_map<int, int> revm;
      int nodes = 0;

      int j;
      for (j = i; j < meetings.size() && meetings[j][2] == time; ++j) {
        const int x = meetings[j][0];
        const int y = meetings[j][1];
        if (m.find(x) == m.end()) {
          m.emplace(x, nodes);
          revm.emplace(nodes, x);
          nodes++;
        }
        if (m.find(y) == m.end()) {
          m.emplace(y, nodes);
          revm.emplace(nodes, y);
          nodes++;
        }
      }

      vector<vector<int>> graph(nodes);
      queue<int> q;
      vector<bool> inq(nodes, false);
      for (j = i; j < meetings.size() && meetings[j][2] == time; ++j) {
        const int x = meetings[j][0];
        const int y = meetings[j][1];
        const int u = m.at(x);
        const int v = m.at(y);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        if (got[x] && !inq[u]) {
          q.push(u);
          inq[u] = true;
        }
        if (got[y] && !inq[v]) {
          q.push(v);
          inq[v] = true;
        }
      }
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
          if (!inq[v]) {
            inq[v] = true;
            got[revm[v]] = true;
            q.push(v);
          }
        }
      }

      i = j;
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i) {
      if (got[i]) {
        answer.emplace_back(i);
      }
    }
    return answer;
  }
};
