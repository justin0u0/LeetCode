/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
 * Runtime: 207ms (78.65%)
 */

class Solution {
public:
  int maxUniqueSplit(const string& s) {
    unordered_set<string> us;
    
    function<int(int)> dfs = [&](int i) {
      if (i == s.length()) {
        return 0;
      }

      int res = 0;
      string str = "";
      for (int j = i; j < s.length(); ++j) {
        str += s[j];
        if (us.find(str) != us.end()) {
          continue;
        }

        auto [it, _] = us.emplace(str);
        res = max(res, dfs(j + 1) + 1);
        us.erase(it);
      }
      return res;
    };
    return dfs(0);
  }
};
