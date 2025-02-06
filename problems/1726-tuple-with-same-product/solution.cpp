/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/tuple-with-same-product/
 * Runtime: 313ms (62.07%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int tupleSameProduct(const vector<int>& nums) {
    const int n = nums.size();

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ++m[nums[i] * nums[j]];
      }
    }

    int res = 0;
    for (auto [k, v] : m) {
      if (v > 1) {
        res += v * (v - 1);
      }
    }
    return res << 2;
  }
};
