/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-words-containing-character/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> findWordsContaining(const vector<string>& words, const char x) {
    vector<int> res;
    for (int i = 0; i < words.size(); ++i) {
      for (char c : words[i]) {
        if (c == x) {
          res.emplace_back(i);
          break;
        }
      }
    }
    return res;
  }
};
