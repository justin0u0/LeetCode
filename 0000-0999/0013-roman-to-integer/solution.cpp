/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/roman-to-integer/
 * Runtime: 15ms
 */

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> m{
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };

    int n = s.length();
    int answer = m[s[n - 1]];
    for (int i = 0; i < n - 1; ++i) {
      int v = m[s[i]];
      if (v < m[s[i + 1]]) {
        answer -= v;
      } else {
        answer += v;
      }
    }

    return answer;
  }
};
