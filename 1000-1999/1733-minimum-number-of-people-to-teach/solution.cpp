/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-people-to-teach/
 * Runtime: 4ms (96.65%)
 */

class Solution {
public:
  int minimumTeachings(const int n, const vector<vector<int>>& languages, const vector<vector<int>>& friendships) {
    const int m = languages.size();

    vector<vector<bool>> langs(m, vector<bool>(n + 1, false));
    for (int i = 0; i < m; ++i) {
      for (const int lang : languages[i]) {
        langs[i][lang] = true;
      }
    }

    const int k = friendships.size();
    vector<bool> needs(m, false);
    for (int i = 0; i < k; ++i) {
      const auto& f = friendships[i];
      bool ok = false;
      for (int j = 1; j <= n; ++j) {
        if (langs[f[0] - 1][j] && langs[f[1] - 1][j]) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        needs[f[0] - 1] = true;
        needs[f[1] - 1] = true;
      }
    }

    int res = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      int teach = 0;
      for (int j = 0; j < m; ++j) {
        if (needs[j] && !langs[j][i]) {
          ++teach;
        }
      }
      res = min(res, teach);
    }
    return res;
  }
};
