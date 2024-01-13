/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
 * Runtime: 21ms (99.70%)
 */

class Solution {
public:
  int minSteps(const string& s, const string& t) {
    int cnt[26] = {0};
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (char c : t) {
      --cnt[c - 'a'];
    }
    int answer = 0;
    for (int c : cnt) {
      if (c > 0) {
        answer += c;
      }
    }
    return answer;
  }
};
