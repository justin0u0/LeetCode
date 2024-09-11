/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-1d-array-into-2d-array/
 * Runtime: 68ms (87.08%)
 */

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) {
      return vector<vector<int>>{};
    }

    vector<vector<int>> arr(m, vector<int>(n));

    int k = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        arr[i][j] = original[k++];
      }
    }
    return arr;
  }
};
