/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Runtime: 60ms
 */

class WordDictionary {
private:
  class Trie {
  public:
    static const int SIZE = 26;

    Trie* next[Trie::SIZE];
    bool exist;

    Trie() {
      for (int i = 0; i < Trie::SIZE; ++i) {
        next[i] = nullptr;
      }
      exist = false;
    }
  };
  
  Trie* trie;
  
  bool dfs(string& word, string::iterator it, Trie* t) {
    if (it == word.end()) {
      return t->exist;
    }
 
    if ((*it) != '.') {
      int idx = (*it) - 'a';

      if (t->next[idx] != nullptr && dfs(word, next(it), t->next[idx])) {
        return true;
      }

      return false;
    }

    for (int i = 0; i < Trie::SIZE; ++i) {
      if (t->next[i] != nullptr && dfs(word, next(it), t->next[i])) {
        return true;
      }
    }

    return false;
  }
public:
  WordDictionary() {
    trie = new Trie();
  }

  void addWord(string word) {
    Trie* cur = trie;

    for (char c : word) {
      int i = c - 'a';
      if (cur->next[i] == nullptr) {
        cur->next[i] = new Trie();
      }
      cur = cur->next[i];
    }
    cur->exist = true;
  }

  bool search(string word) {
    return dfs(word, word.begin(), trie);
  }
};
