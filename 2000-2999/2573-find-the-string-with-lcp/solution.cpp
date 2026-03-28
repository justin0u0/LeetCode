/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-string-with-lcp/
 * Runtime: 7ms (81.93%)
 */

class Solution {
public:
  string findTheString(vector<vector<int>>& lcp) {
    const int n = lcp.size();

    for (int i = 0; i < n; ++i) {
      if (lcp[i][i] != n - i) {
        return "";
      }

      for (int j = 0; j < n; ++j) {
        if (lcp[i][j] != lcp[j][i]) {
          return "";
        }
        if (lcp[i][j] > 0) {
          if (i + 1 < n && j + 1 < n && lcp[i][j] != lcp[i + 1][j + 1] + 1) {
            return "";
          }
          if ((i + 1 >= n || j + 1 >= n) && lcp[i][j] != 1) {
            return "";
          }
        }
      }
    }

    vector<int> mapped(n, -1);
    vector<vector<bool>> valid(n, vector<bool>(26, true));

    string s = "";
    for (int i = 0; i < n; ++i) {
      if (mapped[i] != -1) {
        if (!valid[i][s[mapped[i]] - 'a']) {
          return "";
        }
        s.push_back(s[mapped[i]]);
      } else {
        bool ok = false;
        for (int j = 0; j < 26; ++j) {
          if (valid[i][j]) {
            s.push_back(j + 'a');
            ok = true;
            break;
          }
        }
        if (!ok) {
          return "";
        }
      }

      for (int j = i + 1; j < n; ++j) {
        if (lcp[i][j] > 0) {
          if (mapped[j] != -1 && s[mapped[j]] != s[i]) {
            return "";
          }
          mapped[j] = i;
        } else {
          valid[j][s[i] - 'a'] = false;
        }
      }
    }

    return s;
  }
};
