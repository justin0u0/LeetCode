/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-smallest-number-from-di-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string smallestNumber(const string& pattern) {
    const int n = pattern.size() + 1;

    vector<char> res(n);

    int base = 1;
    for (int i = 0; i < n; ++i) {
      res[i] = i + 1 + '0';
    }

    int j;
    for (int i = 0; i < n - 1; ) {
      if (pattern[i] == 'D') {
        j = i;
        while (j < n - 1 && pattern[j] == 'D') {
          ++j;
        }
        reverse(res.begin() + i, res.begin() + j + 1);
        i = j;
      } else {
        ++i;
      }
    }
    return string(res.begin(), res.end());
  }
};
