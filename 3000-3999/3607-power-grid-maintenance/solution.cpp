/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/power-grid-maintenance/
 * Runtime: 94ms (97.39%)
 */

class Solution {
private:
  int pa[100005];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }

  void merge(int x, int y) {
    x = find(pa[x]);
    y = find(pa[y]);
    if (x != y) {
      if (x < y) {
        swap(x, y);
      }
      pa[x] = y;
    }
  }
public:
  vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    for (int i = 1; i <= c; ++i) {
      pa[i] = i;
    }
    for (const auto& e : connections) {
      merge(e[0], e[1]);
    }

    vector<priority_queue<int, vector<int>, greater<int>>> vpq(c + 1);
    for (int i = 1; i <= c; ++i) {
      vpq[find(i)].push(i);
    }

    vector<bool> online(c + 1, true);
    vector<int> res;
    for (const auto& q : queries) {
      if (q[0] == 1) {
        if (online[q[1]]) {
          res.emplace_back(q[1]);
        } else {
          auto& pq = vpq[find(q[1])];
          while (!pq.empty() && !online[pq.top()]) {
            pq.pop();
          }
          if (pq.empty()) {
            res.emplace_back(-1);
          } else {
            res.emplace_back(pq.top());
          }
        }
      } else {
        online[q[1]] = false;
      }
    }

    return res;
  }
};
