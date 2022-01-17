/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-pattern/
 * Runtime: 0ms
 */

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<string, char> m1;
    unordered_map<string, char>::iterator it;

    string m2[26];

    stringstream ss(s);
    for (char c : pattern) {
      c -= 'a';
      if (!(ss >> s)) {
        return false;
      }

      it = m1.find(s);
      if (it == m1.end()) {
        m1.emplace(s, c);
      } else if (it->second != c) {
        return false;
      }

      if (m2[c] == "") {
        m2[c] = s;
      } else if (m2[c] != s) {
        return false;
      }
    }

    if (ss >> s) {
      return false;
    }

    return true;
  }
};
