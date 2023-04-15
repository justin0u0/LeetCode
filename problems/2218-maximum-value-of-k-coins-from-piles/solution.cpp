/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
 * Runtime: 209ms (96.86%)
 */

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    // cur(i): maximum cost with already i coins taken
    // cur(j) = max{pre(j - i) + sum(top i coins of the current pile)}
    vector<int> pre(k + 1, 0);
    vector<int> cur = pre;
    for (const vector<int>& pile : piles) {
      int sum = 0;
      for (int i = 1; i <= pile.size(); ++i) {
        sum += pile[i - 1];
        for (int j = i; j <= k; ++j) {
          cur[j] = max(cur[j], pre[j - i] + sum);
        }
      }
      pre = cur;
    }

    return pre[k];
  }
};
