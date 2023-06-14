/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/equal-row-and-column-pairs/
 * Runtime: 70ms (99.70%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  long long hr[201];
  long long hc[201];

  const int mod = 1e9 + 7;
  const int base = 172093;
public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      hr[i] = 0;
      hc[i] = 0;
      for (int j = 0; j < n; ++j) {
        hr[i] = (hr[i] * base + grid[i][j]) % mod;
        hc[i] = (hc[i] * base + grid[j][i]) % mod;
      }
    }

    int pairs = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (hr[i] == hc[j]) {
          ++pairs;
        }
      }
    }
    return pairs;
  }
};
