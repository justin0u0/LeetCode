/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
 * Runtime: 14ms (96.75%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxProductDifference(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    return nums[n - 1] * nums[n - 2] - nums[1] * nums[0];
  }
};
