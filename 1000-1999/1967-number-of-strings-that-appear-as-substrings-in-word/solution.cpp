/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 * Runtime: 24ms (8.01%)
 */

class Solution {
private:
  struct Trie {
    Trie* next[26];
    Trie() : next() {}
  };
public:
  int numOfStrings(const vector<string>& patterns, const string& word) {
    auto t = new Trie;

    for (int i = 0; i < word.length(); ++i) {
      auto cur = t;
      for (int j = i; j < word.length(); ++j) {
        const auto c = word[j] - 'a';

        if (cur->next[c] == nullptr) {
          cur->next[c] = new Trie;
        }
        cur = cur->next[c];
      }
    }

    int match = 0;
    for (const auto& pat : patterns) {
      auto cur = t;
      bool ok = true;
      for (const char c : views::transform(pat, [](const auto c) {
        return c - 'a';
      })) {
        if (cur->next[c] == nullptr) {
          ok = false;
          break;
        }
        cur = cur->next[c];
      }
      if (ok) {
        ++match;
      }
    }
    return match;
  }
};
