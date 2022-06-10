/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Runtime: 4ms
 */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> vis(128, false);

    int answer = 0;
    int j = 0;
    int n = (int)s.length();
    for (int i = 0; i < n; ++i) {
      while (vis[s[i]]) {
        vis[s[j]] = false;
        ++j;
      }
      vis[s[i]] = true;

      answer = max(answer, i - j + 1);
    }

    return answer;
  }
};
