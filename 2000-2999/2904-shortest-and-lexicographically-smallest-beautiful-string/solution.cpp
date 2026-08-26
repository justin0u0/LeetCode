/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string shortestBeautifulSubstring(const string& s, const int k) {
    const int n = s.length();

    int cnt = 0;
    int j = 0;
    string res = "";
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++cnt;
      }
      if (cnt < k) {
        continue;
      }
      while (cnt > k) {
        if (s[j] == '1') {
          --cnt;
        }
        ++j;
      }
      while (j < n && s[j] == '0') {
        ++j;
      }

      const auto sub = s.substr(j, i - j + 1);
      if (res == "" || sub.length() < res.length() || (sub.length() == res.length() && sub < res)) {
        res = move(sub);
      }
    }
    return res;
  }
};
