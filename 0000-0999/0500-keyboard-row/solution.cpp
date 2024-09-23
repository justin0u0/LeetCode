/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/keyboard-row/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  constexpr static char* keyboards[3] = {
    "qwertyuiopQWERTYUIOP",
    "asdfghjklASDFGHJKL",
    "zxcvbnmZXCVBNM",
  };

  static array<int, 128> rows;
public:
  vector<string> findWords(const vector<string>& words) {
    vector<string> res;
    for (const auto& w : words) {
      int row = rows[w[0]];
      bool ok = true;
      for (char c : w) {
        if (rows[c] != row) {
          ok = false;
          break;
        }
      }
      if (ok) {
        res.emplace_back(w);
      }
    }
    return res;
  }
};

array<int, 128> Solution::rows = []() {
  array<int, 128> res;
  for (int i = 0; i < 3; ++i) {
    for (char* c = keyboards[i]; *c != '\0'; ++c) {
      res[*c] = i;
    }
  }
  return res;
}();
