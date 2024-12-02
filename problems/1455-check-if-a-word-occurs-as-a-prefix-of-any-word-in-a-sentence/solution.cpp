/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int isPrefixOfWord(const string& sentence, const string& searchWord) {
    const int n = searchWord.length();

    stringstream ss(sentence);
    string s;
    for (int i = 1; ss >> s; ++i) {
      if (s.length() >= n) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
          if (s[j] != searchWord[j]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          return i;
        }
      }
    }
    return -1;
  }
};
