/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/combinations/
 * Runtime: 26ms (76.56%)
 */

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> sols;

    function<void(int i, int j, vector<int>& cur)> dfs = [&](int i, int j, vector<int>& cur) {
      if (j == k) {
        sols.emplace_back(cur);
        return;
      }

      for (; i < n; ++i) {
        cur.emplace_back(i + 1);
        dfs(i + 1, j + 1, cur);
        cur.pop_back();
      }
    };

    vector<int> box;
    dfs(0, 0, box);
    return sols;
  }
};
