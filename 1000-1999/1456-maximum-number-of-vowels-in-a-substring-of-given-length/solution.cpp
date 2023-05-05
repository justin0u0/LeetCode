/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * Runtime: 14ms (96.99%)
 */

class Solution {
private:
  inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
public:
  int maxVowels(const string& s, int k) {
    int count = 0;
    for (int i = 0; i < k; ++i) {
      if (isVowel(s[i])) {
        ++count;
      }
    }

    int answer = count;
    for (int i = k; i < s.size(); ++i) {
      if (isVowel(s[i - k])) {
        --count;
      }
      if (isVowel(s[i])) {
        ++count;
      }
      answer = max(answer, count);
    }
    return answer;
  }
};
