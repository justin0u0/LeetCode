/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pyramid-transition-matrix/
 * Runtime: 321ms (41.08%)
 */

class Solution {
public:
  bool pyramidTransition(const string& bottom, const vector<string>& allowed) {
    unordered_set<string> ok;
    for (const string& s : allowed) {
      ok.emplace(s);
    }

    unordered_map<string, bool> dp;

    function<bool(string, string, int)> dfs = [&](string s, string next, int i) -> bool {
      if (s.length() == 1) {
        return true;
      }

      if (i == 1 && dp.find(s) != dp.end()) {
        return dp.at(s);
      }

      for (char c = 'A'; c <= 'F'; ++c) {
        if (ok.count(string(1, s[i - 1]) + s[i] + c) == 0) {
          continue;
        }

        next.push_back(c);
        if (i + 1 >= s.length()) {
          if (dfs(next, "", 1)) {
            return true;
          }
        } else {
          if (dfs(s, next, i + 1)) {
            if (i == 1) {
              dp.emplace(s, true);
            }
            return true;
          }
        }
        next.pop_back();
      }

      if (i == 1) {
        dp.emplace(s, false);
      }
      return false;
    };
    return dfs(bottom, "", 1);
  }
};
