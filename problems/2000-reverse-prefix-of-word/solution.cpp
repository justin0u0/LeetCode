/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-prefix-of-word/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string reversePrefix(string& word, char ch) {
    for (int i = 0; i < word.size(); ++i) {
      if (word[i] == ch) {
        for (int j = 0; j <= i / 2; ++j) {
          swap(word[j], word[i - j]);
        }
        break;
      }
    }
    return word;
  }
};
