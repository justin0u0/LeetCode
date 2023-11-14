/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
 * Runtime: 342ms (41.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countPalindromicSubsequence(const string& s) {
    vector<int> right(26);
    for (int i = 0; i < s.length(); ++i) {
      right[s[i] - 'a'] = i;
    }

    int answer = 0;
    vector<vector<bool>> vis(26, vector<bool>(26, false));
    vector<bool> left(26, false);
    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'a';
      for (int j = 0; j < 26; ++j) {
        if (left[j] && right[j] > i && !vis[c][j]) {
          vis[c][j] = true;
          ++answer;
        }
      }
      left[c] = true;
    }
    return answer;
  }
};
