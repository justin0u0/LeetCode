/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
 * Runtime: 10ms (91.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();

    unordered_map<string, int> box;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      string s;
      s.reserve(m);

      bool flip = (matrix[i][0] == 1);
      for (int j = 0; j < m; ++j) {
        s.push_back(matrix[i][j] ^ flip);
      }
      mx = max(mx, ++box[s]);
    }
    return mx;
  }
};
