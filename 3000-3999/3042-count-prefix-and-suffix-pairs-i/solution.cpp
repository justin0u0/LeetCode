/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countPrefixSuffixPairs(vector<string>& words) {
    unordered_map<string, int> m;
    int pairs = 0;
    for (const auto& word : words) {
      for (int i = 0; i < word.size(); ++i) {
        string pre = word.substr(0, i + 1);
        string suf = word.substr(word.size() - i - 1);
        if (pre == suf) {
          pairs += m[pre];
        }
      }
      ++m[word];
    }
    return pairs;
  }
};
