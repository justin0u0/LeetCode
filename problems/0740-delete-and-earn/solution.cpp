/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-and-earn/
 * Runtime: 7ms
 * Description:
 *  dp(i) -> maximum earn when numbers are from 1 ~ i
 *  dp(i) = max(
 *    dp(i - 2) + [sum of all number i] -> takes i
 *    dp(i - 1)                         -> not takes i
 *  )
 */

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    const int n = 10001;

    vector<int> count(n, 0);
    for (const int& num : nums) {
      ++count[num];
    }

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = count[1];

    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    }

    return max(dp[n - 1], dp[n - 2]);
  }
};

