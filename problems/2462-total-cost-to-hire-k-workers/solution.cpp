/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/total-cost-to-hire-k-workers/
 * Runtime: 228ms (46.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({INT_MAX, 0});

    int l = 0;
    int r = costs.size() - 1;
    while (candidates--) {
      if (l <= r) {
        pq.push({costs[l], l});
        ++l;
      }
      if (l <= r) {
        pq.push({costs[r], r});
        --r;
      }
    }

    long long answer = 0;
    for (int i = 0; i < k; ++i) {
      auto [cost, idx] = pq.top();
      pq.pop();
      if (l <= r) {
        if (idx < l) {
          pq.push({costs[l], l});
          ++l;
        } else {
          pq.push({costs[r], r});
          --r;
        }
      }
      answer += cost;
    }

    return answer;
  }
};
