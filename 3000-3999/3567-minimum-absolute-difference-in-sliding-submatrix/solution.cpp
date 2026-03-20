/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
 * Runtime: 9ms (88.89%)
 */

class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, INT_MAX));
    vector<int> arr;
    arr.reserve(k * k);

    for (int i = 0; i + k <= m; ++i) {
      for (int j = 0; j + k <= n; ++j) {
        arr.clear();
        for (int i2 = i; i2 < i + k; ++i2) {
          for (int j2 = j; j2 < j + k; ++j2) {
            arr.emplace_back(grid[i2][j2]);
          }
        }
        sort(arr.begin(), arr.end());
        arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

        int& diff = res[i][j];
        for (int i = 1; i < arr.size(); ++i) {
          diff = min(diff, arr[i] - arr[i - 1]);
        }
        if (diff == INT_MAX) {
          diff = 0;
        }
      }
    }
    return res;
  }
};
