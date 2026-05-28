/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-common-suffix-queries/
 * Runtime: 386ms (90.74%)
 */

class Solution {
private:
  struct Trie {
    int next[26];
    int best;

    Trie() : best(-1) {
      memset(next, -1, sizeof(next));
    }
  };
public:
  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    vector<Trie> trie{{}};

    auto compare = [&](int i, int j) {
      return wordsContainer[i].length() < wordsContainer[j].length() ||
        (wordsContainer[i].length() == wordsContainer[j].length() && i < j);
    };

    auto trans = views::transform([](char c) {
      return c - 'a';
    });

    for (int i = 0; i < wordsContainer.size(); ++i) {
      string& s = wordsContainer[i];
      ranges::reverse(s);

      int t = 0;
      for (const char c : s | trans) {
        if (trie[t].best < 0 || compare(i, trie[t].best)) {
          trie[t].best = i;
        }
        if (trie[t].next[c] < 0) {
          trie[t].next[c] = trie.size();
          trie.emplace_back();
        }
        t = trie[t].next[c];
      }
      if (trie[t].best < 0 || compare(i, trie[t].best)) {
        trie[t].best = i;
      }
    }

    vector<int> res(wordsQuery.size());
    for (int i = 0; i < wordsQuery.size(); ++i) {
      string& s = wordsQuery[i];
      ranges::reverse(s);

      int t = 0;
      for (const char c : s | trans) {
        if (trie[t].next[c] < 0) {
          break;
        }
        t = trie[t].next[c];
      }
      res[i] = trie[t].best;
    }
    return res;
  }
};
