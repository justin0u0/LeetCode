/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-strings-alternately/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string mergeAlternately(const string& word1, const string& word2) {
    string answer;
    answer.reserve(word1.size() + word2.size());
    for (int i = 0; i < max(word1.size(), word2.size()); ++i) {
      if (i < word1.size()) {
        answer.push_back(word1[i]);
      }
      if (i < word2.size()) {
        answer.push_back(word2[i]);
      }
    }
    return answer;
  }
};
