/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
 * Runtime: 1113ms (57.81%)
 */

#include <format>

class Solution {
public:
  long long minOperations(const vector<int>& nums, const int x, const int k) {
    const int n = nums.size();

    // dp(i, j): minimum operations for nums[0:i] with j subarrays
    //  pick: = dp(i - x, j - 1) + cost
    //  skip: = dp(i - 1, j)
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e15));
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 0;
    }

    // maintain median with 2 multisets
    multiset<int> lo;
    long long lsum = 0;
    multiset<int> hi;
    long long hsum = 0;

    for (int i = 0; i < x; ++i) {
      lo.insert(nums[i]);
      lsum += nums[i];
    }
    for (int i = x; i <= n; ++i) {
      while ((int)lo.size() - (int)hi.size() > 1) {
        auto it = prev(lo.end());
        hsum += *it;
        lsum -= *it;
        hi.insert(*it);
        lo.erase(it);
      }
      while ((int)hi.size() - (int)lo.size() > 0) {
        auto it = hi.begin();
        lsum += *it;
        hsum -= *it;
        lo.insert(*it);
        hi.erase(it);
      }

      const long long median = *lo.rbegin();
      const long long cost = (median * lo.size() - lsum)
        + (hsum - median * hi.size());

      for (int j = 1; j <= k; ++j) {
        dp[i][j] = min(dp[i - x][j - 1] + cost, dp[i - 1][j]);
      }

      if (i >= n) {
        break;
      }
      if (nums[i - x] <= median) {
        lo.erase(lo.find(nums[i - x]));
        lsum -= nums[i - x];
      } else {
        hi.erase(hi.find(nums[i - x]));
        hsum -= nums[i - x];
      }
      if (hi.empty() || (!lo.empty() && nums[i] <= *lo.rbegin())) {
        lo.insert(nums[i]);
        lsum += nums[i];
      } else {
        hi.insert(nums[i]);
        hsum += nums[i];
      }
    }

    return dp[n][k];
  }
};
