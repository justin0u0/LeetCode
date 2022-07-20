/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-matching-subsequences/
 * Runtime: 666ms
 */

class Solution {
public:
  int numMatchingSubseq(string& s, vector<string>& words) {
    int n = (int)s.length();
    vector<vector<int>> next(n + 2, vector<int>(26, n + 1));
    for (int i = n - 1; i >= 0; --i) {
      next[i] = next[i + 1];
      next[i][s[i] - 'a'] = i + 1;
    }

    int answer = 0;
    for (const string& word : words) {
      int cur = 0;
      for (const char& c : word) {
        cur = next[cur][c - 'a'];
      }
      if (cur != n + 1) {
        ++answer;
      }
    }

    return answer;
  }
};
