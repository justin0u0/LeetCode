/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
 * Runtime: 107ms (79.42%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> queryResults(const int limit, const vector<vector<int>>& queries) {
    unordered_map<int, int> m;
    unordered_map<int, int> color;
    int colors = 0;

    vector<int> result;
    result.reserve(queries.size());
    for (const auto& q : queries) {
      if (color[q[0]] != 0) {
        if (--m[color[q[0]]] == 0) {
          --colors;
        }
      }
      color[q[0]] = q[1];
      if (++m[q[1]] == 1) {
        ++colors;
      }
      result.emplace_back(colors);
    }
    return result;
  }
};
