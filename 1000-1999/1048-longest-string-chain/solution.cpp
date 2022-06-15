/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-string-chain/
 * Runtime: 186ms
 */

class Solution {
private:
  bool check(string& pre, string& nxt) {
    if (pre.size() + 1 != nxt.size()) {
      return false;
    }

    int i = 0;
    int n = (int)pre.size();

    while (i < n && pre[i] == nxt[i]) {
      ++i;
    }
    while (i < n && pre[i] == nxt[i + 1]) {
      ++i;
    }

    return (i == n);
  }
  
  static bool compare(const string& a, const string& b) {
    return a.length() < b.length();
  }
public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), Solution::compare);

    int n = (int)words.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (check(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
