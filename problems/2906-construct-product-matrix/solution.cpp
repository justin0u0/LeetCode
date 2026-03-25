/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-product-matrix/
 * Runtime: 1401ms (5.13%)
 */

class Solution {
private:
  const int B = 320;
  const int mod = 12345;
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<int> muls(B, 1);
    vector<vector<int>> nums(B, vector<int>(B, 1));
    int id = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int page = id / B;
        const int offset = id % B;
        const int g = grid[i][j] % mod;
        muls[page] = muls[page] * g % mod;
        nums[page][offset] = g;
        ++id;
      }
    }


    id = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int page = id / B;
        const int offset = id % B;

        int& res = grid[i][j];
        res = 1;
        
        for (int k = 0; k < B; ++k) {
          if (k != page) {
            res = res * muls[k] % mod;
          }
          if (k != offset) {
            res = res * nums[page][k] % mod;
          }
        }
        ++id;
      }
    }

    return grid;
  }
};
