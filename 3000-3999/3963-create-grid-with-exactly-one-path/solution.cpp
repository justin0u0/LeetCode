/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/create-grid-with-exactly-one-path/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<string> createGrid(const int m, const int n) {
    vector<string> res(m, string(n, '#'));
    for (int i = 0; i < n; ++i) {
      res[0][i] = '.';
    }
    for (int i = 0; i < m; ++i) {
      res[i][n - 1] = '.';
    }
    return res;
  }
};
