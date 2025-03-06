/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-missing-and-repeated-values/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int cnt[2502];
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    const int n = grid.size();
    memset(cnt, 0, n * n * sizeof(int));
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ++cnt[grid[i][j]];
      }
    }

    int a;
    int b;
    for (int i = 1; i <= n * n; ++i) {
      if (cnt[i] > 1) {
        a = i;
      } else if (cnt[i] < 1) {
        b = i;
      }
    }
    return {a, b};
  }
};
