/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/most-profit-assigning-work/
 * Runtime: 24ms (99.74%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    const int n = difficulty.size();
    vector<pair<int, int>> assignments(n);
    for (int i = 0; i < n; ++i) {
      assignments[i] = {difficulty[i], profit[i]};
    }

    sort(assignments.begin(), assignments.end());
    sort(worker.begin(), worker.end());

    int i = 0;
    int sum = 0;
    int maxp = 0;
    for (int w : worker) {
      while (i < n && w >= assignments[i].first) {
        maxp = max(maxp, assignments[i].second);
        ++i;
      }
      sum += maxp;
    }
    return sum;
  }
};
