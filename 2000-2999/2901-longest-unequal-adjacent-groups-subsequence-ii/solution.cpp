/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/
 * Runtime: 39ms (84.38%)
 */

class Solution {
public:
  vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    const int n = words.size();
    vector<int> dp(n, 1);
    vector<int> next(n, -1);

    auto ok = [&](int i, int j) {
      if (words[i].length() != words[j].length()) {
        return false;
      }
      if (groups[i] == groups[j]) {
        return false;
      }
      bool diff = false;
      for (int k = 0; k < words[i].length(); ++k) {
        if (words[i][k] != words[j][k]) {
          if (diff) {
            return false;
          }
          diff = true;
        }
      }
      return true;
    };

    int longest = 0;
    int last = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[i] < dp[j] + 1 && ok(i, j)) {
          dp[i] = dp[j] + 1;
          next[i] = j;
        }
      }
      if (dp[i] > longest) {
        longest = dp[i];
        last = i;
      }
    }

    vector<string> res;
    res.reserve(longest);
    for (int i = last; i != -1; i = next[i]) {
      res.emplace_back(words[i]);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
