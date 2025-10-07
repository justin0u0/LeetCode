/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/avoid-flood-in-the-city/
 * Runtime: 120ms (64.12%)
 */

class Solution {
public:
  vector<int> avoidFlood(const vector<int>& rains) {
    const int n = rains.size();

    set<int> s;
    unordered_map<int, int> m;
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
      const int r = rains[i];
      if (r == 0) {
        s.emplace(i);
        continue;
      }

      auto it = m.find(r);
      if (it != m.end()) {
        auto x = s.lower_bound(it->second);
        if (x == s.end()) {
          return {};
        }
        res[*x] = r;
        s.erase(x);
        it->second = i;
      } else {
        m.emplace(r, i);
      }
    }

    for (int x : s) {
      res[x] = 1;
    }

    return res;
  }
};
