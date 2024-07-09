/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/average-waiting-time/
 * Runtime: 120ms (99.12%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    long long wait = 0;
    int t = 0;
    for (const auto& c : customers) {
      t = max(t, c[0]) + c[1];
      wait += t - c[0];
    }
    return 1.0 * wait / customers.size();
  }
};
