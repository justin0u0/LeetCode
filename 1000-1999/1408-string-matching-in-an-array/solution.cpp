/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/string-matching-in-an-array/
 * Runtime: 17ms (7.20%)
 */

class Solution {
private:
  class Trie {
  public:
    Trie* next[128];
    int freq;

    Trie() : next(), freq(0) {}
  };
public:
  vector<string> stringMatching(vector<string>& words) {
    Trie* root = new Trie;

    for (const auto& word : words) {
      for (int i = 0; i < word.length(); ++i) {
        string s = word.substr(i);
        Trie* cur = root;
        for (char c : s) {
          if (cur->next[c] == nullptr) {
            cur->next[c] = new Trie;
          }
          cur = cur->next[c];
          ++cur->freq;
        }
      }
    }

    vector<string> res;
    for (const auto& word : words) {
      Trie* cur = root;
      for (char c : word) {
        cur = cur->next[c];
      }
      if (cur->freq > 1) {
        res.emplace_back(word);
      }
    }
    return res;
  }
};
