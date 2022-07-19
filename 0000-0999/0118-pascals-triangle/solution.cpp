/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pascals-triangle/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    for (int i = 0; i < numRows; ++i) {
      answer[i] = vector<int>(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
      }
    }
    return answer;
  }
};
