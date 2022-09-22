/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * Runtime: 22ms
 */

class Solution {
public:
  string reverseWords(string& s) {
    int prev = 0;
    string answer;
    answer.reserve(s.size() + 1);
    do {
      int next = s.find(' ', prev);
      string r = s.substr(prev, next - prev);
      reverse(r.begin(), r.end());
      answer.append(r);
      answer.push_back(' ');
      prev = next + 1;
    } while (prev != string::npos + 1);

    answer.pop_back();
    return answer;
  }
};
