/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxProduct(const vector<int>& nums) {
    int max1 = 0;
    int max2 = 0;
    for (int num : nums) {
      if (num > max1) {
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max2 = num;
      }
    }
    return (max1 - 1) * (max2 - 1);
  }
};
