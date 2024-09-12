/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * Runtime: 23ms (99.67%)
 */

class Solution {
public:
  int countConsistentStrings(const string& allowed, const vector<string>& words) {
    bitset<26> b;
    for (char c : allowed) {
      b.set(c - 'a');
    }

    int answer = 0;
    for (const auto& w : words) {
      bool ok = true;
      for (char c : w) {
        if (!b.test(c - 'a')) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++answer;
      }
    }
    return answer;
  }
};
