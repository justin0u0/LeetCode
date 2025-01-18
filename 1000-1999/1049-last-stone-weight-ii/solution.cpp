/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/last-stone-weight-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  bool dp[3001];
public:
  int lastStoneWeightII(vector<int>& stones) {
    const int total = accumulate(stones.begin(), stones.end(), 0);
    memset(dp, false, total * sizeof(bool));
    dp[0] = true;

    for (int s : stones) {
      for (int i = total; i >= s; --i) {
        dp[i] |= dp[i - s];
      }
    }

    for (int i = (total >> 1); i >= 0; --i) {
      if (dp[i] || dp[total - i]) {
        return abs(total - i - i);
      }
    }
    return -1;
  }
};
