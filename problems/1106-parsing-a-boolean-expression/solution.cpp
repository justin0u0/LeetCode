/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/parsing-a-boolean-expression/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool parseBoolExpr(const string& expression) {
    function<bool()> orExpr;
    function<bool()> andExpr;
    function<bool()> notExpr;
    function<bool()> expr;
    int i = 0;

    orExpr = [&]() {
      bool res = false;
      while (true) {
        res |= expr();
        if (expression[i++] == ')') {
          break;
        }
      }
      return res;
    };

    andExpr = [&]() {
      bool res = true;
      while (true) {
        res &= expr();
        if (expression[i++] == ')') {
          break;
        }
      }
      return res;
    };

    notExpr = [&]() {
      auto e = expr();
      ++i;
      return !e;
    };

    expr = [&]() {
      switch (expression[i]) {
        case 't':
          ++i;
          return true;
        case 'f':
          ++i;
          return false;
        case '!': 
          i += 2;
          return notExpr();
        case '|':
          i += 2;
          return orExpr();
        case '&':
          i += 2;
          return andExpr();
      }
      return false;
    };

    return expr();
  }
};
