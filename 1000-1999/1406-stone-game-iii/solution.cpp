/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-iii/
 * Runtime: 209ms (96.45%)
 */

const auto static _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int dp[50001];
public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int& d = dp[i];
      d = stoneValue[i] - dp[i + 1];
      if (i + 2 <= n) {
        d = max(d, stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
      }
      if (i + 3 <= n) {
        d = max(d, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
      }
    }

    int d = dp[0];
    if (d > 0) {
      return "Alice";
    }
    if (d < 0) {
      return "Bob";
    }
    return "Tie";
  }
};
