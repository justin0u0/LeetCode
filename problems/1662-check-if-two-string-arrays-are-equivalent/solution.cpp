/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * Runtime: 0ms (100.0%)
 */

class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0;
    int j = 0;
    for (const string& s : word1) {
      for (const char& c : s) {
        if (i == word2.size() || c != word2[i][j]) {
          return false;
        }
        ++j;
        if (j == word2[i].size()) {
          ++i;
          j = 0;
        }
      }
    }

    return i == word2.size();
  }
};
