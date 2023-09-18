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

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * Runtime: 7ms (82.57%)
 */

class Solution {
public:
  vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> box(mat.size());
    for (int i = 0; i < mat.size(); ++i) {
      const auto& row = mat[i];
      box[i] = {count(row.begin(), row.end(), 1), i};
    }
    sort(box.begin(), box.end());

    vector<int> answer;
    answer.reserve(mat.size());
    transform(box.begin(), box.begin() + k, back_inserter(answer), [](const pair<int, int>& p) {
      return p.second;
    });
    return answer;
  }
};
