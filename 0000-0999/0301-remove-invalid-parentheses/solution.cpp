/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-invalid-parentheses/
 * Runtime: 30ms (78.22%)
 */

class Solution {
public:
  vector<string> removeInvalidParentheses(const string& s) {
    const int n = s.length();

    int minr = INT_MAX;
    unordered_set<string> res;
    string cur = "";

    auto gen = [&](this auto&& self, int i, int left, int rem) {
      if (left < 0 || i + left > n || rem > minr) {
        return;
      }
      if (i >= n) {
        if (rem < minr) {
          minr = rem;
          res.clear();
          res.emplace(cur);
        } else if (rem == minr) {
          res.emplace(cur);
        }
        return;
      }

      if (s[i] != '(' && s[i] != ')') {
        cur.push_back(s[i]);
        self(i + 1, left, rem);
        cur.pop_back();
        return;
      }

      // skip
      self(i + 1, left, rem + 1);

      // take
      cur.push_back(s[i]);
      const int delta = s[i] == '(' ? 1 : -1;
      self(i + 1, left + delta, rem);
      cur.pop_back();
    };
    gen(0, 0, 0);

    return {res.begin(), res.end()};
  }
};
