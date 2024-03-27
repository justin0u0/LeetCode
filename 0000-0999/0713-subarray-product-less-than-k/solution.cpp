/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subarray-product-less-than-k/
 * Runtime: 36ms (99.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numSubarrayProductLessThanK(const vector<int>& nums, const int k) {
    int j = 0;
    int answer = 0;
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prod *= nums[i];
      while (j <= i && prod >= k) {
        prod /= nums[j];
        ++j;
      }
      answer += (i - j + 1);
    }
    return answer;
  }
};
