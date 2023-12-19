/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/image-smoother/
 * Runtime: 31ms (98.15%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int n = img.size();
    int m = img[0].size();

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      vector<int>& row = sum[i + 1];
      inclusive_scan(img[i].begin(), img[i].end(), next(row.begin()));
      transform(row.begin(), row.end(), sum[i].begin(), row.begin(), plus<int>{});
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x0 = max(i - 1, 0);
        int y0 = max(j - 1, 0);
        int x1 = min(i + 2, n);
        int y1 = min(j + 2, m);
        img[i][j] = (sum[x1][y1] - sum[x1][y0] - sum[x0][y1] + sum[x0][y0]) / (x1 - x0) / (y1 - y0);
      }
    }
    return img;
  }
};
