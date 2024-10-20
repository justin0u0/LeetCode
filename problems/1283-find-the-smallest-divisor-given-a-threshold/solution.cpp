/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * Runtime: 7ms (99.90%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int smallestDivisor(const vector<int>& nums, int threshold) {
    int l = 1;
    int r = 1e6;
    while (l <= r) {
      int mid = (l + r) >> 1;

      long long sum = 0;
      for (int num : nums) {
        sum += (num - 1) / mid + 1;
      }
      if (sum <= threshold) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r + 1;
  }
};
