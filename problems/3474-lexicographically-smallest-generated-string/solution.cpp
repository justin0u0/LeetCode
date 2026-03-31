/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-smallest-generated-string/
 * Runtime: 19ms (54.24%)
 */

class Solution {
public:
  string generateString(const string& str1, const string& str2) {
    const int n = str1.size();
    const int m = str2.size();

    vector<char> gen(n + m - 1, 'a');
    vector<bool> fixed(n + m - 1, false);

    for (int i = 0; i < n + m - 1; ++i) {
      if (i < n && str1[i] == 'T') {
        for (int j = i; j < i + m; ++j) {
          if (fixed[j] && gen[j] != str2[j - i]) {
            return "";
          }
          gen[j] = str2[j - i];
          fixed[j] = true;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (str1[i] == 'F') {
        if (string(gen.begin() + i, gen.begin() + i + m) == str2) {
          bool ok = false;
          for (int j = i + m - 1; j >= i; --j) {
            if (!fixed[j]) {
              gen[j] = 'b';
              ok = true;
              break;
            }
          }
          if (!ok) {
            return "";
          }
        }
      }
    }

    return string(gen.begin(), gen.end());
  }
};
