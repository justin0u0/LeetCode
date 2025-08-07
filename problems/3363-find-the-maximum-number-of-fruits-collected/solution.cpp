/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
 * Runtime: 28ms (92.21%)
 */

class Solution {
public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    const int n = fruits.size();
    int coll = 0;
    for (int i = 0; i < n; ++i) {
      coll += fruits[i][i];
      fruits[i][i] = 0;
    }

    vector<vector<int>> dp1(n + 1, vector<int>(n, 0));
    dp1[n - 1][0] = fruits[n - 1][0];
    for (int j = 1; j < n; ++j) {
      for (int i = n - 1; i >= max(n - j - 1, j); --i) {
        dp1[i][j] = max(max(dp1[i - 1][j - 1], dp1[i][j - 1]), dp1[i + 1][j - 1]) + fruits[i][j];
      }
    }
    
    vector<vector<int>> dp2(n, vector<int>(n + 1, 0));
    dp2[0][n - 1] = fruits[0][n - 1];
    for (int i = 1; i < n; ++i) {
      for (int j = n - 1; j >= max(n - i - 1, i); --j) {
        dp2[i][j] = max(max(dp2[i - 1][j - 1], dp2[i - 1][j]), dp2[i - 1][j + 1]) + fruits[i][j];
      }
    }

    return coll + dp1[n - 1][n - 1] + dp2[n - 1][n - 1];
  }
};
