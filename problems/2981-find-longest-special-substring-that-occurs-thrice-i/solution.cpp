/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumLength(string& s) {
    s.push_back('$');

    int mx[128] = {0};
    int mx2[128] = {0};
    int mx3[128] = {0};

    int count = 1;
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] != s[i + 1]) {
        if (count > mx[s[i]]) {
          mx3[s[i]] = mx2[s[i]];
          mx2[s[i]] = mx[s[i]];
          mx[s[i]] = count;
        } else if (count > mx2[s[i]]) {
          mx3[s[i]] = mx2[s[i]];
          mx2[s[i]] = count;
        } else if (count > mx3[s[i]]) {
          mx3[s[i]] = count;
        }
        count = 1;
      } else {
        ++count;
      }
    }

    int answer = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
      answer = max(answer, mx[i] - 2);
      answer = max(answer, min(mx[i] - 1, mx2[i]));
      answer = max(answer, min(mx[i], min(mx2[i], mx3[i])));
    }
    if (answer == 0) {
      return -1;
    }
    return answer;
  }
};
