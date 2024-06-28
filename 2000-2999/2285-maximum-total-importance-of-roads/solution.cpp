/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-total-importance-of-roads/
 * Runtime: 200ms (99.66%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> deg(n, 0);
    for (const auto& e : roads) {
      ++deg[e[0]];
      ++deg[e[1]];
    }
    sort(deg.begin(), deg.end());
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += 1LL * (i + 1) * deg[i];
    }
    return sum;
  }
};
