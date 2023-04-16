/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
 * Runtime: 171ms (97.85%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  // dp(i, j) number of ways before index i for all words to form target[0:j]
  // dp(i, j) = dp(i-1, j-1) * count{word[i] == target[j]} + dp(i-1, j)
  
  // Memory optimization
  // 1. two 1-D array
  //   cur[j] = pre[j - 1] * count{word[i] == target[j]} + pre[j]
  // 2. one 1-D array
  //   loop j from high to low to reuse the dp array
  //   dp[j] = dp[j - 1] * count{word[i] == target[j]} + dp[j]
  int numWays(const vector<string>& words, const string& target) {
    int n = words[0].size();
    int m = target.size();
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      int count[128] = {0};
      for (const string& word : words) {
        ++count[word[i]];
      }

      for (int j = m; j >= 1; --j) {
        dp[j] = (1LL * dp[j - 1] * count[target[j - 1]] + dp[j]) % mod;
      }
    }

    return dp[m];
  }
};
