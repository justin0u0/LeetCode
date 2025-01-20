/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/first-completely-painted-row-or-column/
 * Runtime: 4ms (95.12%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int firstCompleteIndex(const vector<int>& arr, const vector<vector<int>>& mat) {
    const int n = mat.size();
    const int m = mat[0].size();
    vector<int> order(n * m + 1);
    for (int i = 0; i < n * m; ++i) {
      order[arr[i]] = i;
    }

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int mx = 0;
      for (int j = 0; j < m; ++j) {
        mx = max(mx, order[mat[i][j]]);
      }
      res = min(res, mx);
    }
    for (int j = 0; j < m; ++j) {
      int mx = 0;
      for (int i = 0; i < n; ++i) {
        mx = max(mx, order[mat[i][j]]);
      }
      res = min(res, mx);
    }
    return res;
  }
};
