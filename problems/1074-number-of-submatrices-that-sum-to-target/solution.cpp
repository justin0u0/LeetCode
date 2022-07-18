/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
 * Runtime: 1130ms
 */

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> pre(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      pre[i][0] = matrix[i][0];
      for (int j = 1; j < m; ++j) {
        pre[i][j] = pre[i][j - 1] + matrix[i][j];
      }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> sum(vector<int>(m, 0));
      for (int j = i; j < n; ++j) {
        sum[0] += pre[j][0];
        for (int k = 1; k < m; ++k) {
          sum[k] += pre[j][k];
        }

        unordered_map<int, int> box;
        box.emplace(0, 1);
        for (int k = 0; k < m; ++k) {
          answer += box[sum[k] - target];
          ++box[sum[k]];
        }
      }
    }

    return answer;
  }
};
