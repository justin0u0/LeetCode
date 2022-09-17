/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-pairs/
 * Runtime: 832 ms (90.40%)
 */

class Solution {
private:
  bool isPalindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }

      ++i;
      --j;
    }

    return true;
  }

  class Trie {
  public:
    Trie* next[26];
    int index;
    vector<int> box;

    Trie(): next(), index(-1) {}
  };
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    Trie t;
    for (int i = 0; i < words.size(); ++i) {
      const string& s = words[i];
      Trie* cur = &t;

      for (int j = (int)s.length() - 1; j >= 0; --j) {
        if (isPalindrome(s, 0, j)) {
          cur->box.emplace_back(i);
        }

        const int c = s[j] - 'a';
        if (cur->next[c] == nullptr) {
          cur->next[c] = new Trie;
        }
        cur = cur->next[c];
      }
      cur->index = i;
      cur->box.emplace_back(i);
    }

    vector<vector<int>> answer;
    for (int i = 0; i < words.size(); ++i) {
      const string& s = words[i];
      int n = s.length();
      Trie* cur = &t;

      for (int j = 0; cur != nullptr && j < n; ++j) {
        if (cur->index != -1 && cur->index != i && isPalindrome(s, j, n - 1)) {
          answer.emplace_back(vector<int>{i, cur->index});
        }

        cur = cur->next[s[j] - 'a'];
      }

      if (cur != nullptr) {
        for (const int j : cur->box) {
          if (i != j) {
            answer.emplace_back(vector<int>{i, j});
          }
        }
      }
    }
    return answer;
  }
};
