/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-split-array/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int waysToSplitArray(const vector<int>& nums) {
    long long r = accumulate(nums.begin(), nums.end(), 0LL);
    long long l = 0;
    int ways = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      l += nums[i];
      r -= nums[i];
      if (l >= r) {
        ++ways;
      }
    }
    return ways;
  }
};
