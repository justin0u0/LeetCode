/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/short-encoding-of-words/
 * Runtime: 104ms
 */

class Trie {
private:
  const static int SIZE = 26;

  Trie** nxt;
public:
  Trie() {
    nxt = new Trie*[SIZE]();
  }

  static void add(Trie* t, const string& s) {
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
      if (t->nxt[(*it) - 'a'] == nullptr) {
        t->nxt[(*it) - 'a'] = new Trie;
      }

      t = t->nxt[(*it) - 'a'];
    }
  }

  static int countLeaves(Trie* t, int d) {
    int sum = 0;

    for (int i = 0; i < SIZE; ++i) {
      if (t->nxt[i] != nullptr) {
        sum += countLeaves(t->nxt[i], d + 1);
      }
    }

    if (sum == 0) {
      return d;
    }

    return sum;
  }
};

class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    Trie* t = new Trie;

    for (const string& word: words) {
      Trie::add(t, word);
    }

    return Trie::countLeaves(t, 1);
  }
};
