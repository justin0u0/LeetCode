/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-duplicate-letters/
 * Runtime: 5ms
 */

class Solution {
public:
  string removeDuplicateLetters(string& s) {
    int n = (int)s.length();
    vector<int> last(26);
    for (int i = 0; i < n; ++i) {
      last[s[i] - 'a'] = i;
    }

    vector<int> v;
    vector<bool> used(26, false);
    for (int i = 0; i < n; ++i) {
      if (used[s[i] - 'a']) {
        continue;
      }

      while (!v.empty() && s[v.back()] > s[i] && last[s[v.back()] - 'a'] > i) {
        used[s[v.back()] - 'a'] = false;
        v.pop_back();
      }

      used[s[i] - 'a'] = true;
      v.emplace_back(i);
    }

    string answer = "";
    for (int i : v) {
      answer += s[i];
    }
    return answer;
  }
};
