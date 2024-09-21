/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/generate-parentheses/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    
    function<void(int, int, string)> dfs = [&](int i, int j, string s) {
      if (i == n && j == n) {
        res.emplace_back(s);
        return;
      }
      if (i < n) {
        dfs(i + 1, j, s + '(');
      }
      if (j < i) {
        dfs(i, j + 1, s + ')');
      }
    };
    dfs(0, 0, "");
    return res;
  }
};
