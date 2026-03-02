/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minSwaps(vector<vector<int>>& grid) {
    const int n = grid.size();

    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j) {
        ++count;
      }
      grid[0][i] = count;
    }

    auto& zeros = grid[0];

    int swaps = 0;
    for (int i = 0; i < n; ++i) {
      const int low = n - i - 1;
      int j = i;
      while (j < n && zeros[j] < low) {
        ++j;
      }
      if (j >= n) {
        return -1;
      }
      swaps += j - i;
      rotate(zeros.begin() + i, zeros.begin() + j, zeros.begin() + j + 1);
    }
    return swaps;
  }
};
