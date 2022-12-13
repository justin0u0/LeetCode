/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-falling-path-sum/
 * Runtime: 11ms (98.46%)
 */

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
      return matrix[0][0];
    }

    for (int i = 1; i < n; ++i) {
      const vector<int>& prerow = matrix[i - 1];
      vector<int>& row = matrix[i];
      row[0] += min(prerow[0], prerow[1]);
      for (int j = 1; j < n - 1; ++j) {
        row[j] += min(min(prerow[j - 1], prerow[j]), prerow[j + 1]);
      }
      row[n - 1] += min(prerow[n - 1], prerow[n - 2]);
    }

    int answer = 0x3f3f3f3f;
    vector<int>& lastrow = matrix[n - 1];
    for (int i = 0; i < n; ++i) {
      answer = min(answer, lastrow[i]);
    }
    return answer;
  }
};

