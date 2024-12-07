/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
 * Runtime: 24ms (93.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumSize(const vector<int>& nums, const int maxOperations) {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end()) + 1;
    while (l < r) {
      const int mid = (l + r) >> 1;

      int ops = 0;
      for (int num : nums) {
        ops += (num - 1) / mid;
      }
      if (ops <= maxOperations) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
