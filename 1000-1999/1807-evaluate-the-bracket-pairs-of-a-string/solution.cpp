/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
 * Runtime: 43ms (100.00%)
 */

class Solution {
public:
  string evaluate(const string& s, const vector<vector<string>>& knowledge) {
    unordered_map<string_view, string_view> m;
    m.reserve(knowledge.size());
    for (const auto& kv : knowledge) {
      m.emplace(kv[0], kv[1]);
    }

    const int n = s.length();
    const string_view sv = s;
    string res = "";
    res.reserve(n);

    int pos;
    bool skip = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        pos = i + 1;
        skip = true;
      } else if (s[i] == ')') {
        const int len = i - pos;
        const auto key = sv.substr(pos, len);
        if (const auto it = m.find(key); it != m.end()) {
          res += it->second;
        } else {
          res += "?";
        }
        skip = false;
      } else if (!skip) {
        res.push_back(s[i]);
      }
    }

    return res;
  }
};
