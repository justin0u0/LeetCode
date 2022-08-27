/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
 * Runtime: 1626ms
 */

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int x) {
    int n = matrix.size();
    int m = matrix[0].size();
    int answer = -0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
      vector<int> sum(m, 0);
      for (int j = i; j < n; ++j) {
        int s = 0;
        set<int> box{0};
        for (int k = 0; k < m; ++k) {
          s += matrix[j][k];
          sum[k] += s;
          auto it = box.lower_bound(sum[k] - x);
          if (it != box.end()) {
            answer = max(answer, sum[k] - (*it));
          }
          box.emplace(sum[k]);
        }
      }
    }

    return answer;
  }
};
