/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-difference/
 * Runtime: 0ms
 */

class Solution {
public:
  char findTheDifference(string s, string t) {
    char cur = 0;
    for (const char& c : s) {
      cur ^= c;
    }
    for (const char& c : t) {
      cur ^= c;
    }

    return cur;
  }
};
