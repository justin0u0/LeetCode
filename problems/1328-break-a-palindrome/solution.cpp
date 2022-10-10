/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/break-a-palindrome/
 * Runtime: 0ms (100.0%)
 */

class Solution {
public:
  string breakPalindrome(string& palindrome) {
    int n = palindrome.size();
    if (n == 1) {
      return "";
    }

    for (int i = 0; i < n / 2; ++i) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }

    palindrome.back() = 'b';
    return palindrome;
  }
};
