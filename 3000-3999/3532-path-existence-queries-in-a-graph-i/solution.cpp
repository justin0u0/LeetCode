/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
 * Runtime: 7ms (83.84%)
 */

class Solution {
public:
  vector<bool> pathExistenceQueries(const int n, const vector<int>& nums, const int maxDiff, const vector<vector<int>>& queries) {
    vector<int> group(n, 0);

    int g = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] > maxDiff) {
        ++g;
      }
      group[i] = g;
    }

    return queries
      | views::transform([&](const auto& query) {
        return group[query[0]] == group[query[1]];
      })
      | ranges::to<vector<bool>>();
  }
};
