/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * Runtime: 12ms (84.94%)
 */

class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();
    vector<int> rows(n, INT_MAX);
    vector<int> cols(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        rows[i] = min(rows[i], matrix[i][j]);
        cols[j] = max(cols[j], matrix[i][j]);
      }
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (rows[i] == cols[j]) {
          answer.emplace_back(rows[i]);
        }
      }
    }
    return answer;
  }
};
