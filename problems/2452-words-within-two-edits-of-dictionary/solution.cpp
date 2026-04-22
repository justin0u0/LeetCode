/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/words-within-two-edits-of-dictionary/
 * Runtime: 6ms (66.84%)
 */

class Solution {
public:
  vector<string> twoEditWords(const vector<string>& queries, const vector<string>& dictionary) {
    vector<string> res;
    for (const auto& s : queries) {
      for (const auto& t : dictionary) {
        int edits = 0;
        for (int k = 0; k < s.length(); ++k) {
          if (s[k] != t[k]) {
            ++edits;
          }
        }
        if (edits <= 2) {
          res.emplace_back(s);
          break;
        }
      }
    }
    return res;
  }
};
