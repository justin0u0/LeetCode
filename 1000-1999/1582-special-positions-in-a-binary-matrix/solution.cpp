/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
 * Runtime: 13ms (83.42%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int rows[100] = {0};
    int cols[100] = {0};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }
      }
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
          ++answer;
        }
      }
    }
    return answer;
  }
};

