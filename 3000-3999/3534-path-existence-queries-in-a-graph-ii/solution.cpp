/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
 * Runtime: 668ms (5.26%)
 */

class Solution {
public:
  vector<int> pathExistenceQueries(const int n, vector<int>& nums, const int maxDiff, const vector<vector<int>>& queries) {
    vector<int> indices(n);
    ranges::iota(indices, 0);
    ranges::sort(views::zip(nums, indices));

    vector<int> mapped(n);
    for (int i = 0; i < n; ++i) {
      mapped[indices[i]] = i;
    }

    const int m = 16;
    // jump[i][j] is the leftmost index to reach from i with 2^j jumps
    //  : jump[i][0] = k
    //  : jump[i][j] = jump[jump[i][j - 1]][j - 1]
    // where k is the leftmost index to reach from i with 1 jumps
    vector<vector<int>> jump(n, vector<int>(m + 1, 0));

    int k = 0;
    for (int i = 1; i < n; ++i) {
      while (nums[i] - nums[k] > maxDiff) {
        ++k;
      }
      jump[i][0] = k;
      for (int j = 1; j <= m; ++j) {
        jump[i][j] = jump[jump[i][j - 1]][j - 1];
      }
    }

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& query : queries) {
      auto u = mapped[query[0]];
      auto v = mapped[query[1]];

      if (u == v) {
        res.emplace_back(0);
        continue;
      }
      if (u > v) {
        swap(u, v);
      }

      int dist = 0;
      for (int i = m; i >= 0; --i) {
        if (jump[v][i] > u) {
          v = jump[v][i];
          dist += (1 << i);
        }
      }
      if (dist > 1e5) {
        res.emplace_back(-1);
      } else {
        res.emplace_back(dist + 1);
      }
    }
    return res;
  }
};
