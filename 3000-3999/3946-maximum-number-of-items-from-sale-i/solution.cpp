/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
 * Runtime: 102ms (78.41%)
 */

class Solution {
public:
  int maximumSaleItems(const vector<vector<int>>& items, const int budget) {
    vector<int> dp(budget + 1, 0);
    const int n = items.size();
    for (int i = 0; i < n; ++i) {
      const int cost = items[i][1];
      int value = 1;
      for (int j = 0; j < n; ++j) { 
        if (i != j && items[j][0] % items[i][0] == 0) {
          ++value;
        }
      }
      for (int j = cost; j <= budget; ++j) {
        dp[j] = max(dp[j], dp[j - cost] + 1);
      }
      for (int j = budget; j >= cost; --j) {
        dp[j] = max(dp[j], dp[j - cost] + value);
      }
    }
    return dp[budget];
  }
};
