/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/most-beautiful-item-for-each-query/
 * Runtime: 31ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end(), [&](const auto& l, const auto& r) {
      return l[0] < r[0];
    });

    const int n = queries.size();

    vector<pair<int, int>> sorted;
    sorted.reserve(n);
    for (int i = 0; i < n; ++i) {
      sorted.push_back({queries[i], i});
    }
    sort(sorted.begin(), sorted.end());

    vector<int> res(n);
    int j = 0;
    int p = 0;
    for (auto [q, i] : sorted) {
      while (j != items.size() && items[j][0] <= q) {
        p = max(p, items[j][1]);
        ++j;
      }
      res[i] = p;
    }
    return res;
  }
};
