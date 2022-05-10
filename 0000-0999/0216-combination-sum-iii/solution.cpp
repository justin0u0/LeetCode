/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/combination-sum-iii/
 * Runtime: 0ms
 */

class Solution {
private:
  void dfs(vector<vector<int>>& answer, vector<int>& box, int i, int k, int n) {
    if (n == 0 && k == 0) {
      answer.emplace_back(box);
      return;
    }

    if (i > 9 || k <= 0 || i > n) {
      return;
    }

    box.emplace_back(i);
    dfs(answer, box, i + 1, k - 1, n - i);
    box.pop_back();

    dfs(answer, box, i + 1, k, n);
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> answer;
    vector<int> box;
    box.reserve(k);
    dfs(answer, box, 1, k, n);

    return answer;
  }
};
