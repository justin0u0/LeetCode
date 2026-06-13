/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/weighted-word-mapping/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string mapWordWeights(const vector<string>& words, const vector<int>& weights) {
    string s;
    s.reserve(words.size());
    for (const auto& word : words) {
      int sum = 0;
      for (char c : word) {
        sum += weights[c - 'a'];
      }
      s += 'z' - sum % 26;
    }
    return s;
  }
};
