/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Runtime: 9ms (93.37%)
 */

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<long long> s;
    for (const string& token : tokens) {
      if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) {
        s.push(stoi(token));
      } else {
        long long y = s.top();
        s.pop();
        long long x = s.top();
        s.pop();
        switch (token[0]) {
        case '+':
          s.push(x + y);
          break;
        case '-':
          s.push(x - y);
          break;
        case '*':
          s.push(x * y);
          break;
        case '/':
          s.push(x / y);
          break;
        }
      }
    }

    return s.top();
  }
};
