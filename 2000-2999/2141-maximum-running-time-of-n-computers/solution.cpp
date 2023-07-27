/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 * Runtime: 122ms (99.64%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maxRunTime(int n, vector<int>& batteries) {
    sort(batteries.begin(), batteries.end());
    int m = batteries.size();

    long long extra = 0;
    for (int i = 0; i < m - n; ++i) {
      extra += batteries[i];
    }

    for (int i = m - n; i < m - 1; ++i) {
      long long j = i - m + n + 1;
      long long needs = (batteries[i + 1] - batteries[i]) * j;
      if (extra < needs) {
        return batteries[i] + extra / j;
      }
      extra -= needs;
    }

    return batteries.back() + extra / n;
  }
};
