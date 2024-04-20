/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-groups-of-farmland/
 * Runtime: 66ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> answer;

    const int n = land.size();
    const int m = land[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (land[i][j] == 1) {
          int i2 = i;
          int j2 = j;
          while (i2 < n && land[i2][j] == 1) {
            ++i2;
          }
          while (j2 < m && land[i][j2] == 1) {
            ++j2;
          }
          for (int x = i; x < i2; ++x) {
            for (int y = j; y < j2; ++y) {
              land[x][y] = 0;
            }
          }
          answer.emplace_back(vector<int>{i, j, i2 - 1, j2 - 1});
        }
      }
    }

    return answer;
  }
};
