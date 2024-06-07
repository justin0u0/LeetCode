/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/replace-words/
 * Runtime: 49ms (97.09%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class Trie {
  private:
    vector<Trie*> next;
    bool ok;
  public:
    Trie(): next(26, nullptr), ok(false) {}

    static void insert(Trie* root, const string& s) {
      Trie* t = root;
      for (char c : s) {
        c -= 'a';
        if (t->next[c] == nullptr) {
          t->next[c] = new Trie;
        }
        t = t->next[c];
      }
      t->ok = true;
    }

    static int lcp(Trie* root, const string& s) {
      Trie* t = root;
      for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if (t->next[c] == nullptr) {
          return s.length();
        }
        t = t->next[c];
        if (t->ok) {
          return i + 1;
        }
      }
      return s.length();
    }
  };
public:
  string replaceWords(vector<string>& dictionary, const string& sentence) {
    Trie* root = new Trie;
    for (const string& s : dictionary) {
      Trie::insert(root, s);
    }

    stringstream ss(sentence);
    string res = "";
    string s;
    while (ss >> s) {
      res += s.substr(0, Trie::lcp(root, s));
      res += ' ';
    }
    res.pop_back();
    return res;
  }
};
