/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/different-ways-to-add-parentheses/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> diffWaysToCompute(const string& expression) {
    vector<int> expr;
    stringstream ss(expression);
    
    int num;
    char op;
    ss >> num;
    expr.emplace_back(num);
    while (ss >> op >> num) {
      expr.emplace_back(op);
      expr.emplace_back(num);
    }

    vector<int> answer;
    function<vector<int>(vector<int>)> dfs = [&](const vector<int> expr) {
      if (expr.size() == 1) {
        return expr;
      }

      vector<int> res;
      for (int i = 1; i < expr.size(); i += 2) {
        auto l = dfs(vector<int>(expr.begin(), expr.begin() + i));
        auto r = dfs(vector<int>(expr.begin() + i + 1, expr.end()));

        for (int x : l) {
          for (int y : r) {
            switch (expr[i]) {
              case '+':
                res.emplace_back(x + y);
                break;
              case '-':
                res.emplace_back(x - y);
                break;
              case '*':
                res.emplace_back(x * y);
                break;
            }
          }
        }
      }
      return res;
    };
    return dfs(expr);
  }
};
