/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * Runtime: 14ms
 */

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int rows = 0;
    vector<pair<int, int>> box;
    for (const vector<int>& row : mat) {
      int sum = 0;
      for (const int& val : row) {
        sum += val;
      }

      box.emplace_back(sum, rows++);
    }

    sort(box.begin(), box.end());

    vector<int> answer;
    for (int i = 0; i < k; ++i) {
      answer.emplace_back(box[i].second);
    }

    return answer;
  }
};
