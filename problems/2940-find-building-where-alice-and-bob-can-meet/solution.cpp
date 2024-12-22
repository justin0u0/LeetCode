/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/
 * Runtime: 69ms (84.08%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    // Let maxI be the maximum building index of a query, and maxH being the
    // maximum height of the 2 buildings of a query.
    //
    // Then for each query, we want to find the leftmost building index i,
    // where i >= maxI and heights[i] > maxH.
    //
    // We can maintain a decreasing subequence from the rightmost building to
    // the `maxI`th building, then find the smallest height in the subsequence
    // which is greater than the `maxH`, which then is the leftmost building
    // index i >= maxI and heights[i] > maxH.

    const int n = heights.size();
    const int m = queries.size();

    vector<vector<pair<int, int>>> qm(n); // map `maxI` into query of {i, maxH}
    vector<int> res(m, -1);
    for (int i = 0; i < m; ++i) {
      const int a = queries[i][0];
      const int b = queries[i][1];

      if (a == b || heights[min(a, b)] < heights[max(a, b)]) {
        res[i] = max(a, b);
        continue;
      }
      qm[max(a, b)].push_back({i, max(heights[a], heights[b])});
    }

    vector<pair<int, int>> decr;
    for (int i = n - 1; i >= 0; --i) {
      while (!decr.empty() && decr.back().first <= heights[i]) {
        decr.pop_back();
      }
      decr.push_back({heights[i], i});

      for (const auto [qi, maxH] : qm[i]) {
        auto it = lower_bound(decr.rbegin(), decr.rend(), pair{maxH + 1, 0});
        if (it != decr.rend()) {
          res[qi] = it->second;
        }
      }
    }

    return res;
  }
};
