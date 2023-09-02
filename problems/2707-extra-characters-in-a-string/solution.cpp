/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/extra-characters-in-a-string/
 * Runtime: 72ms (96.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int dp[52] = {0};
public:
  int minExtraChar(const string& s, const vector<string>& dictionary) {
    unordered_set<string> m;
    for (const string& word : dictionary) {
      m.emplace(word);
    }
    int n = s.length();
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int& d = dp[i];
      d = dp[i + 1] + 1;

      string temp = "";
      temp.reserve(n - i);
      for (int j = i; j < n; ++j) {
        temp += s[j];
        if (m.find(temp) != m.end()) {
          d = min(d, dp[j + 1]);
        }
      }
    }
    return dp[0];
  }
};
