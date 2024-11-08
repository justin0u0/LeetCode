/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-xor-for-each-query/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    const int base = (1 << maximumBit) - 1;
    int x = 0;
    for (int& num : nums) {
      x ^= num;
      num = x ^ base;
    }

    reverse(nums.begin(), nums.end());
    return nums;
  }
};
