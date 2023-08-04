/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-break/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
#define MAX_LENGTH 20
public:
  bool wordBreak(const string& s, vector<string>& wordDict) {
    vector<unordered_set<string>> box(MAX_LENGTH + 1);
    for (const string& w : wordDict) {
      box[w.length()].emplace(w);
    }

    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
      if (!dp[i]) {
        continue;
      }

      string cur;
      cur.reserve(MAX_LENGTH);
      for (int j = 0; j < min(MAX_LENGTH, n - i); ++j) {
        cur.push_back(s[i + j]);
        const auto& b = box[j + 1];
        if (b.find(cur) != b.end()) {
          dp[i + j + 1] = dp[i + j + 1] | dp[i];
        }
      }
    }

    return dp[n];
  }
};
