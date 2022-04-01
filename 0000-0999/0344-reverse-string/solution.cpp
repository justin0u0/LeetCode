/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-string/
 * Runtime: 26ms
 */

class Solution {
public:
  void reverseString(vector<char>& s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; ++i) {
      swap(s[i], s[n - i - 1]);
    }
  }
};
