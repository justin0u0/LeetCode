/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 * Runtime: 64ms (90.87%)
 */

class Solution {
public:
  long long gcdSum(vector<int>& nums) {
    const auto n = nums.size();

    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, nums[i]);
      nums[i] = gcd(nums[i], mx);
    }
    ranges::sort(nums);

    long long sum = 0;
    for (int i = 0; i < n / 2; ++i) {
      sum += gcd(nums[i], nums[n - i - 1]);
    }
    return sum;
  }
};
