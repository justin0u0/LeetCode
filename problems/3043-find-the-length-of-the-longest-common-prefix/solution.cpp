/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 * Runtime: 114ms (99.77%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class Trie {
  public:
    Trie* next[10];
    Trie() : next() {}
  };
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie* root = new Trie;

    array<char, 10> digits;
    for (int num : arr1) {
      int j = -1;
      while (num != 0) {
        digits[++j] = num % 10;
        num /= 10;
      }

      Trie* cur = root;
      for (int i = j; i >= 0; --i) {
        if (cur->next[digits[i]] == nullptr) {
          cur->next[digits[i]] = new Trie;
        }
        cur = cur->next[digits[i]];
      }
    }

    int lcp = 0;
    for (int num : arr2) {
      int j = -1;
      while (num != 0) {
        digits[++j] = num % 10;
        num /= 10;
      }

      Trie* cur = root;
      for (int i = j; i >= 0; --i) {
        if (cur->next[digits[i]] == nullptr) {
          break;
        }

        cur = cur->next[digits[i]];
        lcp = max(lcp, j - i + 1);
      }
    }
    return lcp;
  }
};
