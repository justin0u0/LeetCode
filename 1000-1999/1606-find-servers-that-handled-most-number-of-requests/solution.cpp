/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
 * Runtime: 146ms (60.38%)
 */

class Solution {
public:
  vector<int> busiestServers(const int k, const vector<int>& arrival, const vector<int>& load) {
    vector<int> used(k, 0);

    set<int> free;
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<PII>> busy; // time, server
    for (int i = 0; i < k; ++i) {
      free.emplace(i);
    }

    const int n = arrival.size();
    for (int i = 0; i < n; ++i) {
      while (!busy.empty() && busy.top().first <= arrival[i]) {
        free.emplace(busy.top().second);
        busy.pop();
      }

      if (free.empty()) {
        continue;
      }

      auto it = free.lower_bound(i % k);
      if (it == free.end()) {
        it = free.begin();
      }

      ++used[*it];
      busy.push({arrival[i] + load[i], *it});
      free.erase(it);
    }

    const auto target = *ranges::max_element(used);
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      if (used[i] == target) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};
