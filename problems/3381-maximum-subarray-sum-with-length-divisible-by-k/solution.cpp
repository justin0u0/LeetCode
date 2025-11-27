/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
 * Runtime: 8ms (77.82%)
 */

class Solution {
public:
  long long maxSubarraySum(const vector<int>& nums, const int k) {
    vector<long long> slot(k, 1e18);
    slot[0] = 0;

    long long res = -1e18;
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      long long& s = slot[(i + 1) % k];
      res = max(res, sum - s);
      s = min(s, sum);
    }
    return res;
  }
};
