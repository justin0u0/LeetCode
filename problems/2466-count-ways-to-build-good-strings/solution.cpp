/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-ways-to-build-good-strings/
 * Runtime: 10ms (90.26%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  void inline add(int& x, int a) {
    x += a;
    if (x >= mod) {
      x -= mod;
    }
  }

  int dp[100001];
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int answer = 0;
    dp[0] = 1;
    for (int i = 1; i <= high; ++i) {
      dp[i] = 0;
      if (i >= zero) {
        add(dp[i], dp[i - zero]);
      }
      if (i >= one) {
        add(dp[i], dp[i - one]);
      }
      if (i >= low) {
        add(answer, dp[i]);
      }
    }
    return answer;
  }
};
