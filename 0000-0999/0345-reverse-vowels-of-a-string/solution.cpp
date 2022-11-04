/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Runtime: 10ms
 */

class Solution {
private:
  bool isVowel(const char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  }
public:
  string reverseVowels(string& s) {
    int i = 0;
    int j = (int)s.length() - 1;
    while (i < j) {
      if (!isVowel(s[i])) {
        ++i;
      } else if (!isVowel(s[j])) {
        --j;
      } else {
        swap(s[i], s[j]);
        ++i;
        --j;
      }
    }

    return s;
  }
};
