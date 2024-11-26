/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-champion-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<bool> indeg(n, false);
    for (const auto& e : edges) {
      indeg[e[1]] = true;
    }

    int res = -1;
    for (int i = 0; i < n; ++i) {
      if (!indeg[i] && res != -1) {
        return -1;
      }
      if (!indeg[i]) {
        res = i;
      }
    }
    return res;
  }
};
