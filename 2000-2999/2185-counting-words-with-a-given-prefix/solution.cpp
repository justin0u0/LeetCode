/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/counting-words-with-a-given-prefix/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int prefixCount(const vector<string>& words, const string& pref) {
    const int n = pref.length();

    int count = 0;
    for (const auto& w : words) {
      if (w.length() >= n && w.substr(0, n) == pref) {
        ++count;
      }
    }
    return count;
  }
};
