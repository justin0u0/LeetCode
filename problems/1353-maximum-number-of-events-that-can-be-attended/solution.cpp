/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * Runtime: 55ms (92.26%)
 */

class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    const int n = events.size();

    sort(events.begin(), events.end(), [&](const auto& l, const auto& r) {
      return l[0] < r[0];
    });

    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;
    int res = 0;
    for (int d = 1; d <= 100000; ++d) {
      while (i < n && events[i][0] <= d) {
        pq.push(events[i][1]);
        ++i;
      }

      while (!pq.empty() && pq.top() < d) {
        pq.pop();
      }
      if (!pq.empty()) {
        ++res;
        pq.pop();
      }
    }
    return res;
  }
};
