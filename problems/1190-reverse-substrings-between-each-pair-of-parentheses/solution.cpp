/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string reverseParentheses(string& s) {
    int cur = 0;
    stack<int> stk;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        stk.push(cur);
      } else if (s[i] == ')') {
        reverse(s.begin() + stk.top(), s.begin() + cur);
        stk.pop();
      } else {
        s[cur++] = s[i];
      }
    }

    return s.substr(0, cur);
  }
};
