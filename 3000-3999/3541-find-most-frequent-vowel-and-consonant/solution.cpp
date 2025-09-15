/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxFreqSum(const string& s) {
    int count[128] = {0};
    for (const char c : s) {
      ++count[c];
    }
    int f1 = 0;
    int f2 = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        f1 = max(f1, count[c]);
      } else {
        f2 = max(f2, count[c]);
      }
    }
    return f1 + f2;
  }
};
