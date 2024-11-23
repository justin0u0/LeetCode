/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rotating-the-box/
 * Runtime: 150ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    const int n = box.size();
    const int m = box[0].size();
    vector<vector<char>> rot(m, vector<char>(n, '.'));
    for (int i = 0; i < n; ++i) {
      int k = m - 1;
      for (int j = m - 1; j >= 0; --j) {
        if (box[i][j] == '*') {
          rot[j][n - i - 1] = '*';
          k = j - 1;
        } else if (box[i][j] == '#') {
          rot[k][n - i - 1] = '#';
          --k;
        }
      }
    }
    return rot;
  }
};
