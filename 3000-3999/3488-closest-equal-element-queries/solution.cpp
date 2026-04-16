/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/closest-equal-element-queries/
 * Runtime: 439ms (9.45%)
 */

class Solution {
public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    const int m = queries.size();
    vector<int> res(m, INT_MAX);

    unordered_map<int, int> first;
    unordered_map<int, int> last;

    auto sq = queries | views::enumerate | ranges::to<vector>();
    ranges::sort(sq, {}, [&](const auto& q) {
      return get<1>(q);
    });

    int j = 0;
    for (const auto [i, q] : sq) {
      while (j < q) {
        first.emplace(nums[j], j);
        last[nums[j]] = j;
        ++j;
      }
      if (last.find(nums[q]) != last.end()) {
        res[i] = min(q - last[nums[q]], n - q + first[nums[q]]);
      }
    }

    first.clear();
    last.clear();
    j = n - 1;
    for (const auto [i, q] : views::reverse(sq)) {
      while (j > q) {
        first.emplace(nums[j], j);
        last[nums[j]] = j;
        --j;
      }
      if (last.find(nums[q]) != last.end()) {
        res[i] = min(res[i], min(last[nums[q]] - q, n - first[nums[q]] + q));
      }
    }

    ranges::replace(res, INT_MAX, -1);
    return res;
  }
};
