/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/score-of-parentheses/
 * Runtime: 0ms
 */

class Solution {
private:
  int dfs(string& s, int i, int j) {
    if (i == j - 2) {
      return 1;
    }

    int k;
    int count = 1;
    for (k = i + 1; count != 0; ++k) {
      if (s[k] == '(') {
        ++count;
      } else {
        --count;
      }
    }

    if (k == j) {
      return 2 * dfs(s, i + 1, j - 1);
    }

    return dfs(s, i, k) + dfs(s, k, j);
  }
public:
  int scoreOfParentheses(string s) {
    return dfs(s, 0, s.length());
  }
};
