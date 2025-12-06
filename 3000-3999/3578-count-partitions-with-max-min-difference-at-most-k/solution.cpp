/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/
 * Runtime: 221ms (43.92%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int countPartitions(const vector<int>& nums, const int k) {
    const int n = nums.size();

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int j = 0;
    int sum = 1;
    multiset<int> s;

    for (int i = 0; i < n; ++i) {
      s.emplace(nums[i]);
      while (*s.rbegin() - *s.begin() > k) {
        s.erase(s.find(nums[j]));
        sum = (sum - dp[j] + mod) % mod;
        ++j;
      }
      dp[i + 1] = sum;
      sum = (sum + dp[i + 1]) % mod;
    }

    return dp[n];
  }
};
