/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/implement-trie-prefix-tree/
 * Runtime: 48ms (97.60%)
 */

class Trie {
private:
  class TrieNode {
  public:
    char c;
    bool end;
    TrieNode* next[26];

    TrieNode() : c(0), end(false), next() {}
    TrieNode(char c) : c(c), end(false), next() {}
  };

  TrieNode* root;
public:
  Trie() : root(new TrieNode) {}
  
  void insert(const string& word) {
    TrieNode* cur = root;
    for (const char& c : word) {
      char x = c - 'a';
      if (cur->next[x] == nullptr) {
        cur->next[x] = new TrieNode(x);
      }
      cur = cur->next[x];
    }
    cur->end = true;
  }
  
  bool search(const string& word) {
    TrieNode* cur = root;
    for (const char& c : word) {
      char x = c - 'a';
      if (cur->next[x] == nullptr) {
        return false;
      }
      cur = cur->next[x];
    }
    return cur->end == true;
  }
  
  bool startsWith(const string& prefix) {
    TrieNode* cur = root;
    for (const char& c : prefix) {
      char x = c - 'a';
      if (cur->next[x] == nullptr) {
        return false;
      }
      cur = cur->next[x];
    }
    return true;
  }
};
