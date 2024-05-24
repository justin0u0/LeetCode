/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> maxFreq(26, 0);
    for (char c : letters) {
      ++maxFreq[c - 'a'];
    }

    const int n = words.size();
    vector<int> freq(26, 0);

    function<int(int, int)> dfs = [&](int i, int s) {
      if (i == n) {
        return s;
      }

      int res = dfs(i + 1, s);

      for (char c : words[i]) {
        ++freq[c - 'a'];
        s += score[c - 'a'];
      }

      bool ok = true;
      for (int j = 0; j < 26; ++j) {
        if (freq[j] > maxFreq[j]) {
          ok = false;
        }
      }
      if (ok) {
        res = max(res, dfs(i + 1, s));
      }
      for (char c : words[i]) {
        --freq[c - 'a'];
        s -= score[c - 'a'];
      }

      return res;
    };

    return dfs(0, 0);
  }
};
