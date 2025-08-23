/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-submatrices-with-all-ones/
 * Runtime: 2ms (91.20%)
 */

class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    const int n = mat.size();
    const int m = mat[0].size();

    vector<vector<int>> height(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (mat[i - 1][j - 1] == 1) {
          height[i][j] = height[i - 1][j] + 1;
        }
      }
    }

    int submat = 0;
    for (int i = 1; i <= n; ++i) {
      stack<pair<int, int>> stk;
      int total = 0;
      for (int j = 1; j <= m; ++j) {
        int h = height[i][j];
        int w = 1;
        while (!stk.empty() && stk.top().first > h) {
          total -= stk.top().first * stk.top().second;
          w += stk.top().second;
          stk.pop();
        }
        total += h * w;
        stk.push({h, w});
        submat += total;
      }
    }
    return submat;
  }
};
