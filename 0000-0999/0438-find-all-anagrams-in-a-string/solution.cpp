/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Runtime: 11ms
 */

class Solution {
private:
  inline bool check(int* cnt) {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        return false;
      }
    }

    return true;
  }
public:
  vector<int> findAnagrams(string s, string p) {
    int cnt[26] = {0};

    for (const char& c : p) {
      ++cnt[c - 'a'];
    }

    int n = (int)s.length();
    int m = (int)p.length();
    for (int i = 0; i < n && i < m; ++i) {
      --cnt[s[i] - 'a'];
    }

    vector<int> answer;

    for (int i = 0, j = m; j < n; ++i, ++j) {
      if (check(cnt)) {
        answer.emplace_back(i);
      }

      ++cnt[s[i] - 'a'];
      --cnt[s[j] - 'a'];
    }

    if (check(cnt)) {
      answer.emplace_back(n - m);
    }

    return answer;
  }
};
