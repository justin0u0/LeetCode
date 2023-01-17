/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flip-string-to-monotone-increasing/
 * Runtime: 24ms (85.32%)
 */

class Solution {
public:
  int minFlipsMonoIncr(string& s) {
    int r = 0;
    for (const char& c : s) {
      if (c == '1') {
        ++r;
      }
    }

    int n = s.size();
    int answer = n - r;
    int l = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++l;
        --r;
      }
      answer = min(answer, l + n - i - 1 - r);
    }

    return answer;
  }
};
