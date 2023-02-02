/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/verifying-an-alien-dictionary/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isAlienSorted(vector<string>& words, string& order) {
    int m[128] = {0};
    for (int i = 0; i < 26; ++i) {
      m[order[i]] = 'a' + i;
    }
    for (string& word : words) {
      for (char& c : word) {
        c = m[c];
      }
    }
    return is_sorted(words.begin(), words.end());
  }
};
