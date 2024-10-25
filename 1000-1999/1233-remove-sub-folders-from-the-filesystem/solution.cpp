/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
 * Runtime: 121ms (81.87%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class Trie {
  public:
    Trie* next[27];
    bool ok;

    Trie() : next(), ok(false) {}
  };

  inline char trans(const char c) {
    if (c == '/') {
      return 26;
    }
    return c - 'a';
  }
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    Trie* root = new Trie;
    for (const auto& s : folder) {
      Trie* cur = root;
      for (char c : s) {
        c = trans(c);
        if (cur->next[c] == nullptr) {
          cur->next[c] = new Trie;
        }
        cur = cur->next[c];
      }
      cur->ok = true;
    }

    vector<string> res;
    for (const auto& s : folder) {
      Trie* cur = root;
      bool ok = true;
      for (int i = 0; i + 1 < s.length(); ++i) {
        if (cur->ok && s[i] == '/') {
          ok = false;
          break;
        }
        cur = cur->next[trans(s[i])];
      }
      if (ok) {
        res.emplace_back(s);
      }
    }
    return res;
  }
};
