/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-and-replace-pattern/
 * Runtime: 3ms
 */

class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n = (int)pattern.length();
    vector<string> answer;
    for (const string& word : words) {
      char map[128] = {0};
      char rmap[128] = {0};
      bool ok = true;
      for (int i = 0; ok && i < n; ++i) {
        const char p = pattern[i];
        const char w = word[i];
        if (map[p] == 0) {
          map[p] = w;
        }
        if (rmap[w] == 0) {
          rmap[w] = p;
        }

        ok &= (map[p] == w) && (rmap[w] == p);
      }

      if (ok) {
        answer.emplace_back(word);
      }
    }

    return answer;
  }
};
