/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
 * Runtime: 522ms (82.79%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class Trie {
  public:
    Trie* next[26];
    int count;
    Trie() : next(), count(0) {}
  };
public:
  vector<int> sumPrefixScores(const vector<string>& words) {
    Trie* root = new Trie;
    for (const auto& s : words) {
      Trie* cur = root;
      for (int i = 0; i < s.length(); ++i) {
        const char c = s[i] - 'a';
        if (cur->next[c] == nullptr) {
          cur->next[c] = new Trie;
        }
        cur = cur->next[c];
        ++cur->count;
      }
    }

    vector<int> scores;
    scores.reserve(words.size());
    for (const auto& s : words) {
      Trie* cur = root;
      int score = 0;
      for (int i = 0; i < s.length(); ++i) {
        const char c = s[i] - 'a';
        if (cur->next[c] == nullptr) {
          cur->next[c] = new Trie;
        }
        cur = cur->next[c];
        score += cur->count;
      }
      scores.emplace_back(score);
    }
    return scores;
  }
};
